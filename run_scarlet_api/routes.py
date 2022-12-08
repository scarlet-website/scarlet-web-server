import json
import os

import requests
from flask import render_template, redirect, url_for, request

from run_scarlet_api import app
from run_scarlet_api.consts import RoutesConsts


@app.route('/')
def index():
    return render_template(RoutesConsts.INDEX_HTML_FILE)


@app.route('/books', methods=['GET', 'POST'])
def getBooks():
    try:
        with open(RoutesConsts.BOOKS_FILE, encoding='utf-8') as books_json_file:
            data = json.load(books_json_file)
    except Exception as e:
        return f"Error getting books data - {str(e)}"
    return data


@app.route('/purchase', methods=['POST'])
def purchase():
    params = {
        "GroupPrivateToken": os.getenv(key='GROUP_PRIVATE_TOKEN'),
        "RedirectURL": RoutesConsts.REDIRECT_URL,
        "ExemptVAT": True,
        "MaxPayments": 12,
        "details": request.args.get('details'),
        "Items": request.args.get('Items')
    }
    try:
        res = requests.post(url=f"{RoutesConsts.RIVHIT_URL}/GetUrl", params=params)
    except Exception as e:
        return f"Error get url from rivhit - {str(e)}"
    return res.text


@app.route('/redirectURL', methods=['GET'])
def redirect_url():
    return redirect(url_for(RoutesConsts.REDIRECT_FILE))
