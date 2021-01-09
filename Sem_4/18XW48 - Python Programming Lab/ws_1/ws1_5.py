alice_ratings = {"alonzo": 1, "bob": 3, "turing": 2}
bob_ratings = {"alice": 1, "alonzo": 2, "turing": 3}
alonzo_ratings = {"alice": 3, "bob": 2, "turing": 1}
turing_ratings = {"alice": 2, "alonzo": 1, "bob": 3}
friends = {"alice": alice_ratings, "bob": bob_ratings,
           "alonzo": alonzo_ratings, "turing": turing_ratings}


def most_popular(friends):

    friend_score_dict = dict.fromkeys(friends.keys(), 0)

    for key, ratings in friends.items():
        for name, vote in ratings.items():
            friend_score_dict[name] += vote
    temp = min(friend_score_dict.values())
    return str([key for key in friend_score_dict if friend_score_dict[key] == temp])


if __name__ == "__main__":
    print(most_popular(friends))
