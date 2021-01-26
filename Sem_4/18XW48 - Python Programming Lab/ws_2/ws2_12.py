if __name__ == '__main__':
    item_list = ['the', 'dead', 'parrot', 'sketch']
    parrot = item_list
    for item in item_list:
        item = item.capitalize()
        print(item, len(item))