
def main():
    seasons = ['Spring', 'Summer', 'Fall', 'Winter']
    e = enumerate(seasons)

    for i, v in enumerate(seasons):
        print("{} : {}".format(i, v))


if __name__ == "__main__":
    main()