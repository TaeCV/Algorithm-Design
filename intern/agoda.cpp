#include <bits/stdc++.h>
// P krub need help krub
using namespace std;

class Room {
protected:
    string name;
    vector<int> booking_database; // even idx stores check-in-date, odd idx stores check-out-date
public:
    Room() : name("default"), booking_database() {}

    Room(string name) : name(name), booking_database() {}

    bool checking_book_validate(int check_in_date, int check_out_date) {
        if (check_in_date < 1 || check_out_date < 1)
            return false;
        if (check_in_date > 31 || check_out_date > 31)
            return false;
        if (check_in_date > check_out_date)
            return false;
        auto itr_check_in = lower_bound(booking_database.begin(), booking_database.end(), check_in_date);
        auto itr_check_out = lower_bound(booking_database.begin(), booking_database.end(), check_out_date);
        if (check_in_date < *itr_check_in && check_out_date < *itr_check_in || check_in_date > *itr_check_in && check_out_date > *itr_check_in) {
            // the range of the booking date is not overlapping other bookings
            return true;
        }
        return false;
    }

    void add_booking(int booking_id, int check_in_date, int check_out_date) {
        booking_database.push_back(check_in_date);
        booking_database.push_back(check_out_date);
    }

    string get_room_name() {
        return name;
    }

    pair<int, int> get_booking_timeline(int booking_idx) {
        return {booking_database[booking_idx * 2], booking_database[booking_idx * 2 + 1]};
    }
};

class Hotel {
protected:
    int total_booking_id;
    set<string> room_lists;
    vector<Room> rooms;
    vector<pair<int, bool>> booking_order_with_room_id;

public:
    Hotel() : total_booking_id(0), room_lists(), rooms(), booking_order_with_room_id() {}

    void create_room(string name) {
        if (room_lists.find(name) == room_lists.end()) {
            room_lists.insert(name);
            rooms.push_back(Room(name));
        }
    }

    void booking_room(int room_id, int check_in_date, int check_out_date) {
        if (room_id < 1 || room_id > rooms.size())
            return;
        Room room = rooms[room_id - 1];
        if (room.checking_book_validate(check_in_date, check_out_date)) {
            ++total_booking_id;
            room.add_booking(total_booking_id, check_in_date, check_out_date);
            booking_order_with_room_id.push_back({room_id - 1, true});
        }
    }

    void cancel_booking(int booking_id) {
        if (booking_id < 0 || booking_id > total_booking_id)
            return;
        --total_booking_id;
        booking_order_with_room_id[booking_id].second = false;
    }

    void report_all_booking() {
        for (int room_id = 0; room_id < rooms.size(); ++room_id) {
            cout << "Room: " << rooms[room_id].get_room_name() << "\n";
            int count = 0;
            for (int booking_id = 0; booking_id < booking_order_with_room_id.size(); ++booking_id) {
                if (booking_order_with_room_id[booking_id].first == room_id) {
                    if (booking_order_with_room_id[booking_id].second) {
                        pair<int, int> booking_timeline = rooms[room_id].get_booking_timeline(count);
                        cout << "Booking Id " << booking_id << ": " << booking_timeline.first << " -> " << booking_timeline.second << "\n";
                    }
                    ++count;
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    Hotel my_hotel;
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command.compare("create") == 0) {
            cin >> command;
            if (command.compare("room") == 0) {
                string room_name;
                cin >> room_name;
                my_hotel.create_room(room_name);
            }
        } else if (command.compare("book") == 0) {
            int room_id, check_in_date, check_out_date;
            cin >> room_id;
            cin >> check_in_date;
            cin >> check_out_date;
            my_hotel.booking_room(room_id, check_in_date, check_out_date);
        } else if (command.compare("cancel") == 0) {
            int booking_id;
            cin >> booking_id;
            my_hotel.cancel_booking(booking_id);
        } else {
            cout << "wrong command\n";
        }
    }
    my_hotel.report_all_booking();
    return 0;
}
