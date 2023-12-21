const express = require("express");
const axios = require("axios");
const morgan = require("morgan");
const cors = require("cors");

const controller = require("./controller");
const middleware = require("./middlewares");

const PORT = process.env.PORT || 5000;
const app = express();

/* Middlewares */
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cors());
app.use(morgan("dev"));

/* Routes */
app
  .post("/cart/purchase", middleware.purchase_middleware, controller.purchase);

const HOST = "https://scarlet-publishing.com";

/* Start server */
app.listen(PORT, HOST, () =>
  console.log(`App listening at ${HOST}:${PORT}/cart`)
);
