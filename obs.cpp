#include <iostream>
#include <string>

struct Actor {
    std::string name;
    int fans;
    Actor* next;

    Actor(const std::string& n, int f, Actor* nxt) : name(n), fans(f), next(nxt) {}
};

class ActorList {
private:
    Actor* head;

public:
    ActorList() : head(nullptr) {}

    void addActor(const std::string& name, int fans) {
        Actor* curr = head;
        while (curr != nullptr) {
            if (curr->name == name && curr->fans == fans ) {
                std::cout << "NIE" << std::endl;
                return;
            }
            curr = curr->next;
        }

        head = new Actor(name, fans, head);
        std::cout << "TAK" << std::endl;
    }

    void findAndSelectActor(int maxFans) {
        Actor* maxActor = nullptr;
        Actor* curr = head;
        Actor* selectedActor = nullptr;

        while (curr != nullptr) {
            if (curr->fans <= maxFans && (maxActor == nullptr || curr->fans > maxActor->fans)) {
                maxActor = curr;
            }
            curr = curr->next;
        }

        if (maxActor == nullptr) {
            std::cout << "NIE" << std::endl;
        } else {
            curr = head;
            while (curr != nullptr) {
                if (curr->fans == maxActor->fans) {
                    if (selectedActor == nullptr || (curr->name < selectedActor->name)) {
                        selectedActor = curr;
                    }
                }
                curr = curr->next;
            }

            if (selectedActor != nullptr) {
                std::cout << selectedActor->name << std::endl;
                deleteActor(selectedActor->name,selectedActor->fans);
            } else {
                std::cout << "NIE" << std::endl;
            }
        }
    }

    // void deleteActor(const std::string& name, int fans) {
    //     Actor* curr = head;
    //     Actor* prev = nullptr;
    //
    //     while (curr != nullptr) {
    //         if (curr->name == name) {
    //             if (prev != nullptr) {
    //                 prev->next = curr->next;
    //             } else {
    //                 head = curr->next;
    //             }
    //             delete curr;
    //             return;
    //         }
    //         prev = curr;
    //         curr = curr->next;
    //     }
    // }

    void deleteActor(const std::string& name, int fans) {
        Actor* curr = head;
        Actor* prev = nullptr;

        while (curr != nullptr) {
            if (curr->name == name && curr->fans == fans) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

};


// std::string trimSpaces(const std::string& str) {
//
//     size_t start = 0;
//     while (start < str.length() && std::isspace(str[start])) {
//         start++;
//     }
//
//
//     size_t end = str.length();
//     while (end > start && std::isspace(str[end - 1])) {
//         end--;
//     }
//
//
//     return str.substr(start, end - start);
// }




int main() {
    ActorList actorList;

    int n;
    std::cin >> n;

    while (n--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            std::string name;
            int fans;
            getline(std::cin >>std::ws, name);
            //trimSpaces(name);
            std::cin >> fans;
            actorList.addActor(name, fans);
        } else if (op == 2) {
            int maxFans;
            std::cin >> maxFans;
            actorList.findAndSelectActor(maxFans);
        }
    }

    return 0;
}
