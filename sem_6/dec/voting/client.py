import Pyro4

while (True):
    voting_server = Pyro4.Proxy("PYRONAME:voting_server")
    options = """
        1. Register to Vote
        2. Verify Voter
        3. Vote
        4. Tally Results
        5. Announce Winner
        6. Quit
    """
    print(options)
    choice = input("Please Enter your Choice: ")

    match choice:
        case "1":
            name = input("Enter your name: ")
            voter_id = voting_server.register(name)
            print("Your voter id: ", voter_id)

        case "2":
            voter_id = input("Enter your voter id: ")
            if voting_server.verify_voter(voter_id):
                print("Valid voter id")
            else:
                print("Vote already casted or voter id invalid")

        case "3":
            voter_id = input("Enter voter id: ")
            print("Candidates List: ", voting_server.get_candidates_list())
            candidate = input("Enter your candidate of choice: ")
            voting_server.vote(voter_id, candidate)

        case "4":
            print("Results")
            candidates_list = voting_server.tally_results()
            for candidate, votes in candidates_list.items():
                print(candidate, ":", votes)

        case "5":
            print("Winner is", voting_server.announce_winner())

        case "6":
            break

        case _:
            print("Invalid Choice")