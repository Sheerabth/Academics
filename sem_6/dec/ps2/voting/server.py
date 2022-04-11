import Pyro4


@Pyro4.expose
class Server:
    def __init__(self, candidates_file):
        self.__candidates_list = dict()
        self.__voters_list = dict()
        self.__current_id = 0

        candidates = open(candidates_file, "r")
        for candidate in candidates.readlines():
            self.__candidates_list[candidate.strip()] = 0

    def register(self, name):
        if self.__current_id > 999:
            print("Voters limit reached")
            return

        voter_id = "V" + str(self.__current_id).zfill(3)
        self.__voters_list[voter_id] = (name, False)

        self.__current_id += 1

        return voter_id

    def verify_voter(self, voter_id):
        if voter_id in self.__voters_list and self.__voters_list[voter_id][1] == False:
            return True
        else:
            return False

    def vote(self, voter_id, candidate):
        if self.verify_voter(voter_id) and candidate in self.__candidates_list:
            self.__voters_list[voter_id] = (self.__voters_list[voter_id][0], True)
            self.__candidates_list[candidate] += 1

    def tally_results(self):
        return self.__candidates_list

    def get_candidates_list(self):
        return self.__candidates_list.keys()

    def announce_winner(self):
        return max(self.__candidates_list, key=self.__candidates_list.get)


if __name__ == "__main__":
    server = Server(
        "./sem_6/dec/ps2/voting/candidates_list.txt"
    )
    Pyro4.Daemon.serveSimple({server: "voting_server"}, ns=True, verbose=True)
