from math import sqrt
from country import Country
from copy import deepcopy


def fit1(countries):
    a, b = 0, 0
    print("Fit1")
    for country in countries:
        year_acc = 0
        year_squared_acc = 0
        pop_acc = 0
        value_acc = 0
        list_years = list(country.population_by_year)
        years_len = len(list_years)
        for i in range(len(list_years)):
            current_year = list_years[i]
            current_pop = country.population_by_year[current_year]
            year_acc += current_year
            pop_acc += current_pop
            year_squared_acc += pow(current_year, 2)
            value_acc += current_year * current_pop
        result = (years_len * year_squared_acc - pow(year_acc, 2))
        if result == 0:
            exit(84)
        a += (years_len * value_acc - year_acc * pop_acc) / result
        b += (pop_acc * year_squared_acc - year_acc * value_acc) / result
    return a, b


def root_mean_square(countries: list[Country], a, b, is_fit_first):
    if is_fit_first:
        first_country_pop = countries[0].population_by_year
    else:
        first_country_pop = deepcopy(countries[0].population_by_year)
    diff = 0
    for i in range(1, len(countries)):
        temp: Country = countries[i]
        for year in list(temp.population_by_year):
            pop = temp.population_by_year[year]
            first_country_pop[year] += pop

    for year in list(first_country_pop):
        pop = countries[0].population_by_year[year]
        if is_fit_first:
            diff += pow(pop - (a * year + b), 2)
        else:
            #print(f"values[{pop}], year = {year} ; a = {a} ; b = {b}")
            diff += pow(pop - ((-b + year) / a), 2)
    return sqrt(diff / len(first_country_pop))


def population_in_2050(a, b, is_fit_first):
    if is_fit_first:
        return a * 2050 + b
    else:
        return (2050 - b) / a
