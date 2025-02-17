class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> sequences;
        vector<bool> used(tiles.length(), false);
        solve(tiles, "", used, sequences);
        return sequences.size() - 1;
    }

private:
    void solve(string& tiles, string current, vector<bool>& used,
                           unordered_set<string>& sequences) {

        sequences.insert(current);
        for (int pos = 0; pos < tiles.length(); ++pos) {
            if (!used[pos]) {
                used[pos] = true;
                solve(tiles, current + tiles[pos], used, sequences);
                used[pos] = false;
            }
        }
    }
};