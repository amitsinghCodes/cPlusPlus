#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Message {
private:
    string text;
    int id; // Unique identifier for sorting

public:
    Message() : id(0) {} // Default constructor

    Message(const string& txt, int message_id) : text(txt), id(message_id) {}

    const string& get_text() const {
        return text;
    }

    // Sorting operator (needed for std::sort in fix_order)
    bool operator<(const Message& other) const {
        return id < other.id;
    }
};

class MessageFactory {
private:
    int current_id; // Unique ID counter

public:
    MessageFactory() : current_id(0) {}

    Message create_message(const string& text) {
        return Message(text, current_id++); // Assign unique ID to each message
    }
};

class Recipient {
private:
    vector<Message> messages_;

    void fix_order() {
        sort(messages_.begin(), messages_.end()); // Sort messages based on ID
    }

public:
    Recipient() {}

    void receive(const Message& msg) {
        messages_.push_back(msg); // Store received messages
    }

    void print_messages() {
        fix_order(); // Ensure messages are printed in the correct order
        for (const auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear(); // Clear messages after printing
    }
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end()); // Simulate network disorder
        for (const auto& msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;

    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }

    Network::send_messages(messages, recipient);
    recipient.print_messages();

    return 0;
}
