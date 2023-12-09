const axios = require('axios');
const SERVER_ADDRESS = "https://manager-web-server.onrender.com";

const purchase_middleware = async (req, res, next) => {
    console.log("purchase_middleware");
    let badRequest = false;
    let { Items, details } = req.body;

    try {
        const params = {
          no_images: true
        };
        const response = await axios.get(`${SERVER_ADDRESS}/get_books`, { params });
        const apiBooks = response.data.books;

        if (!Items || Items.length === 0) {
          console.warn('No books to purchase');
          res.status(400).send('No books to purchase');
          return;
        }

        req.body.Items = Items.map((book) => {
            const apiBook = apiBooks.find((b) => b.CatalogNumber == book.CatalogNumber);
            if (!apiBook) {
              console.warn(`Book with CatalogNumber ${book.CatalogNumber} not found`);
              res.status(400).send(`Book with CatalogNumber ${book.CatalogNumber} not found`);
              badRequest = true;
              return;
            }
            return {
                ...apiBook,
                Quantity: book.Quantity,
            };
        });

        if (badRequest) {
          console.error("Bad request");
            return;
        }

        next();
    } catch (error) {
        console.error('Error fetching books from the Flask API', error);
        res.status(500).send('Internal Server Error');
    }
};

module.exports = {
    purchase_middleware,
};
