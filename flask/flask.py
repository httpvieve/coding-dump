from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
        return 'This is the <i>home screen</i>.'

if __name__ == '__main__':
        app.run()