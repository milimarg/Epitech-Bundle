from copy import deepcopy
from country import Country


def compute_correlation(countries: list[Country], a1, b1, rms1, a2, b2, rms2):
    if rms1 == 0 or rms2 == 0:
        exit(84)
    first_country_pop = deepcopy(countries[0].population_by_year)
    years_list = list(first_country_pop)
    diff = 0
    for i in range(1, len(countries)):
        temp: Country = countries[i]
        for year in list(temp.population_by_year):
            pop = temp.population_by_year[year]
            first_country_pop[year] += pop
    for year in years_list:
        current_pop = countries[0].population_by_year[year]
        diff += (current_pop - (a1 * year + b1)) * (current_pop - ((-b2 + year) / a2))
    diff /= len(years_list)
    return diff / (rms1 * rms2)
