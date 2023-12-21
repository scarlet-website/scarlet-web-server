const axios = require("axios");
require("dotenv").config();

const rivhit_url = "https://icredit.rivhit.co.il/API/PaymentPageRequest.svc";
const redirectURL = "https://www.scarlet-publishing.com/pages/order_confirm.php";

const purchase = (req, res) => {
  let json_data = {
    GroupPrivateToken: process.env.GROUP_PRIVATE_TOKEN,
    RedirectURL: redirectURL,
    ExemptVAT: false,
    MaxPayments: 12,
    Items: req.body.Items,
    ...req.body.details,
  }
  console.log(`JSON DATA: ${JSON.stringify(json_data)}`);
  axios
    .post(
      `${rivhit_url}/GetUrl`,
      json_data
    )
    .then((response) => {
      const responseUrl = response.data.URL;
      console.log(`responseUrl: ${responseUrl}`);
      res.status(200).json({ iframe_url: responseUrl });
    })
    .catch((error) => {
      console.error(`error: ${error}`);
      res.send(error);
    });
};

module.exports = {
  purchase
};