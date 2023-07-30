const storage = require("mini-db");

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

const purchase_middleware = (req, res, next) => {
    console.log("purchase_middleware");
    let badRequest = false;
    let { Items, details } = req.body;
    const stock = db.select("books");
    if (!Items || Items.length === 0) {
      res.status(400).send("No books to purchase");
      return;
    }
    req.body.Items = Items.map((book) => {
      const stockBook = stock.find((b) => b.CatalogNumber == book.CatalogNumber);
      if (!stockBook) {
        res
          .status(400)
          .send(`Book with CatalogNumber ${book.CatalogNumber} not found`);
        badRequest = true;
        return;
      }
      return {
        ...stockBook,
        Quantity: book.Quantity,
      };
    });
    if (badRequest) {
      return;
    }
    next();
}

const saleDetails_middleware = (req, res, next) => {
    console.log("saleDetails_middleware");
    next();
}

const getBooks_middleware = (req, res, next) => {
    console.log("getBooks_middleware");
    next();
}

const addBook_middleware = (req, res, next) => {
    console.log("addBook_middleware");
    next();
}

module.exports = {
    purchase_middleware,
    saleDetails_middleware,
    getBooks_middleware,
    addBook_middleware
}