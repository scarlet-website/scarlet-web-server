import os
from flask import Flask

app = Flask(__name__)
app.config['SECRET_KEY'] = os.urandom(12)

from run_scarlet_api import routes
