#!/bin/bash

cd "/opt/poll" || exit 0
./venv/bin/gunicorn -b 0.0.0.0:8181 wsgi:app
