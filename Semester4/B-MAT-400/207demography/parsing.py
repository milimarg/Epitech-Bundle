import csv
from sys import argv
from country import Country


def parse_year(years, population_by_year):
    parsed_populations = [float(year.replace(',', '.')) for year in population_by_year]
    result = {}
    for pop, year in zip(parsed_populations, years):
        result[int(year)] = pop
    return result


def parse_data_file(filepath, given_codes):
    data = []
    countries = []
    with open(filepath) as f:
        for row in csv.reader(f, delimiter=';'):
            data.append(row)
        years = [y[2:] for y in data if data.index(y) == 0][0]
        for gc in given_codes:
            for row in data:
                if row[1] == gc:
                    countries.append(Country(row[0], row[1], parse_year(years, row[2:])))
    if len(countries) != len(given_codes):
        exit(84)
    return countries


def get_parsing():
    argc = len(argv)
    if argc <= 1:
        exit(84)
    return parse_data_file("./207demography_data.csv", argv[1:])
