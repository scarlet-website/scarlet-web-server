const axios = require("axios");
const storage = require("mini-db");
require("dotenv").config();

// const fetch = require("node-fetch"); // Import the fetch library if it's not available already.

async function getBooksDataFromURL(url) {
  try {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error("Network response was not ok.");
    }
    return await response.json();
  } catch (error) {
    console.error("Error fetching data:", error);
    return null;
  }
}

async function main() {
  const booksURL = "https://scarlet-website.github.io/api-data/books.json";

  const db = await getBooksDataFromURL(booksURL);
  if (db) {
    // Now you have the data in the db constant, you can use it as you need.
    console.log(db);
  } else {
    console.log("Failed to fetch books data.");
  }
}

main();

// const db = storage("./storage/books.json");
const rivhit_url = "https://icredit.rivhit.co.il/API/PaymentPageRequest.svc/";

let redirectURL = "https://www.scarlet-publishing.com/pages/order_confirm.php";
// if (process.env.NODE_ENV === "production") {
//   redirectURL = "https://scarlet-pub-server.herokuapp.com/redirectURL";
// } else {
//   redirectURL = "http://localhost:5000/redirectURL";
// }

const purchase = (req, res) => {
  axios
    .post(
      `${rivhit_url}/GetUrl`,
      {
        GroupPrivateToken: process.env.GROUP_PRIVATE_TOKEN,
        RedirectURL: redirectURL,
        ExemptVAT: false,
        MaxPayments: 12,
        Items: req.body.Items,
        ...req.body.details,
      }
    )
    .then((response) => {
      placeOrder(response.data);
      res.send(response.data);
    })
    .catch((error) => {
      res.send(error);
    });
};

const placeOrder = (order) => {
  db.insert("orders", {
    PrivateSaleToken: order.PrivateSaleToken,
    PublicSaleToken: order.PublicSaleToken,
  });
};

const saleDetails = (req, res) => {
  const saleToken = req.query.PublicSaleToken || req.body.PublicSaleToken;
  const order = db.select("orders").find((o) => o.PublicSaleToken == saleToken);
  if (!order) {
    res.status(400).send("Order not found");
    return;
  }
  axios
    .post(
      `${rivhit_url}/SaleDetails`,
      {
        "SalePrivateToken": order.PrivateSaleToken,
      }
    )
    .then((response) => {
      res.send(response.data);
    })
    .catch((error) => {
      res.send(error);
    });
};

const getBooks = (req, res) => {
  res.send(db.select("books"));
};

const addBook = (req, res) => {
  const book = req.body;
  const stock = db.select("books");
  const stockBook = stock.find((b) => b.CatalogNumber == book.CatalogNumber);
  if (stockBook) {
    res
      .status(400)
      .send(`Book with CatalogNumber ${book.CatalogNumber} already exists`);
    return;
  } else if (!book.CatalogNumber || !book.Description || !book.UnitPrice) {
    res
      .status(400)
      .send("Book must have an CatalogNumber, Description and UnitPrice");
  } else {
    db.insert("books", book);
    res.send(db.select("books"));
  }
};

module.exports = {
  purchase,
  saleDetails,
  getBooks,
  addBook,
};
