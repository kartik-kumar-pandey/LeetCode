class UndergroundSystem {
public:

    // id -> {station, time}
    unordered_map<int, pair<string, int>> checkInData;

    // "start#end" -> {totalTime, numberOfTrips}
    unordered_map<string, pair<int, int>> trips;

    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {

        // Get check-in information
        string startStation = checkInData[id].first;
        int startTime = checkInData[id].second;

        // Calculate travel time
        int travelTime = t - startTime;

        // Create station pair
        string key = startStation + "#" + stationName;

        // Add travel time
        trips[key].first += travelTime;

        // Add number of trips
        trips[key].second++;
    }

    double getAverageTime(string startStation, string endStation) {

        string key = startStation + "#" + endStation;

        int totalTime = trips[key].first;
        int totalTrips = trips[key].second;

        return (double)totalTime / totalTrips;
    }
};