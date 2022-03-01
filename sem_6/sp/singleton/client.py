from singleton import Database

if __name__ == "__main__":
    db1 = Database.get_instance()
    db2 = Database.get_instance()
    if db1 == db2:
        print("Singleton!")
