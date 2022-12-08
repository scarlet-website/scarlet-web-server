from flask import render_template, redirect, url_for, request

from run_scarlet_api import app


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/all_books', methods=['POST'])
def all_books():
    return "all books"
