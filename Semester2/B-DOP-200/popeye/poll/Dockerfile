FROM python:latest

COPY requirements.txt .

RUN mkdir /static/
RUN mkdir /templates/

COPY app.py /
COPY static/ /static/
COPY templates/ /templates/

RUN pip install --upgrade pip
RUN pip3 install -r requirements.txt

EXPOSE 80

CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]
