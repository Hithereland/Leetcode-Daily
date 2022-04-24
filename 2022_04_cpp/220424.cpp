//
// Created by z on 4/24/2022.
// # 1396
// 很难绷得住
// 我爱西加加
class UndergroundSystem {
public:

    typedef pair<int, string> ckIn;
    typedef pair<int, int> SumToAmount;
    typedef pair<string, string> trav;

    struct PairHash {
        template<typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
    };

    unordered_map<trav, SumToAmount, PairHash> mp;
    unordered_map<ckIn, int, PairHash> inBuf;
    unordered_map<int, string> idToStation;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        idToStation[id] = stationName;
        inBuf[ckIn(id, stationName)] = t;
    }

    void checkOut(int id, string stationName, int t) {

        int timeTaken = t - inBuf[ckIn(id, idToStation[id])];
        trav tmp = trav(idToStation[id], stationName);

        if (mp.find(tmp) == mp.end())
            mp[tmp] = SumToAmount(0,0);

        mp[tmp].first += timeTaken;
        mp[tmp].second++;

        inBuf.erase(ckIn(id, idToStation[id]));
        idToStation.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        trav target = trav(startStation, endStation);
        if (mp.find(target) == mp.end())
            mp[target] = SumToAmount(0,0);
        double ret = double(mp[target].first) / mp[target].second;
        return ret;
    }
};


