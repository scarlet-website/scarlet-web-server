const express = require("express");
const axios = require("axios");
const morgan = require("morgan");
const cors = require("cors");

const controller = require("./controller");
const middleware = require("./middlewares");

const PORT = process.env.PORT || 5001;
const app = express();

/* Middlewares */
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cors());
app.use(morgan("dev"));

/* Routes */
app
  .post("/api/purchase", middleware.purchase_middleware, controller.purchase);


/* Start server */
app.listen(PORT, () =>
  console.log(`App listening at http://localhost:${PORT}/api`)
);
