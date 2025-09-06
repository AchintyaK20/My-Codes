#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_set>
using namespace std;

vector<int> mergeThreeSortedListsWithoutDuplicates(vector<int> A, vector<int> B, vector<int> C) {
    int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < A.size() || j < B.size() || k < C.size()) {
        int valA = (i < A.size()) ? A[i] : INT_MAX;
        int valB = (j < B.size()) ? B[j] : INT_MAX;
        int valC = (k < C.size()) ? C[k] : INT_MAX;

        int minVal = min({valA, valB, valC});

        // Add to result only if it's not a duplicate of the last inserted value
        if (result.empty() || result.back() != minVal) {
            result.push_back(minVal);
        }

        // Advance all pointers that point to the current minimum
        if (i < A.size() && A[i] == minVal) {
            i++;
        }
        if (j < B.size() && B[j] == minVal) {
            j++;
        }
        if (k < C.size() && C[k] == minVal) {
            k++;
        }
    }

    return result;
}

vector<int> mergeThreeSortedLists(vector<int> A, vector<int> B, vector<int> C) {
    int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < A.size() || j < B.size() || k < C.size()) {
        int valA = (i < A.size()) ? A[i] : INT_MAX;
        int valB = (j < B.size()) ? B[j] : INT_MAX;
        int valC = (k < C.size()) ? C[k] : INT_MAX;

        int minVal = min({valA, valB, valC});

        result.push_back(minVal);

        // Advance only the pointer that contributed the minVal
        if (i < A.size() && valA == minVal) {
            i++;
        } else if (j < B.size() && valB == minVal) {
            j++;
        } else if (k < C.size() && valC == minVal) {
            k++;
        }
    }

    return result;
}

pair<int, int> shrinkWindow(pair<int, int> &left, vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    auto &[row, col] = left;
    if (col == n - 1) {
        return {row + 1, 0};
    }
    return {row, col + 1};
}

int maxConsecutiveHolidays(vector<vector<char>> &grid, int pto) {
    int maxVacation = 0;
    int currVacation = 0;
    pair<int, int> left = {0, 0};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'W') {
                --pto;
            }
            currVacation++;
            while (pto < 0) {
                if (grid[left.first][left.second] == 'W') {
                    pto++;
                }
                left = shrinkWindow(left, grid);
                currVacation--;
            }
            maxVacation = max(maxVacation, currVacation);
        }
    }
    return maxVacation;
}

double maxConsecutiveHolidaysVariant(vector<char> days, double pto) {
    int ptoFull = (int)pto;
    double ptoPartial = pto - ptoFull;
    int maxVacation = INT_MIN;
    int l = 0;
    for (int r = 0; r < days.size(); r++) {
        if (days[r] == 'W') {
            --ptoFull;
        }
        while (pto < 0) {
            if (days[l] == 'W') {
                ++ptoFull;
            }
            l++;
        }
        maxVacation = max(maxVacation, r - l + 1);
    }
    if (maxVacation < days.size()) {
        maxVacation += ptoPartial;
    }
    return maxVacation;
}

bool validWordAbbreviationVariant(string word, string abbr) {
    int i = 0, j = 0;
    while (i < abbr.size() && j < word.size()) {
        if (islower(abbr[i])) {
            if (abbr[i] != word[j]) {
                return false;
            }
            i++, j++;
        } else if (isdigit(abbr[i])) {
            int total = 0;
            int firstCharIdx = i;
            while (i < abbr.size() && isdigit(abbr[i])) {
                total = total * 10 + (abbr[i] - '0');
                i++;
            }
            if (total == 0) {
                continue;
            } else {
                j += total;
            }
        }
    }
    return i == abbr.size() && j == word.size();
}

bool validWordAbbrVariant2(string abbr1, string abbr2) {
    int i = 0;
    int j = 0;
    int skipA = 0, skipB = 0;
    int m = abbr1.size(), n = abbr2.size();
    while (i < m || j < n) {
        if (i < m && isdigit(abbr1[i])) {
            int num = 0;
            if (abbr1[i] == '0') {
                return false;
            }
            while (i < m && isdigit(abbr1[i])) {
                num = num * 10 + (abbr1[i] - '0');
                i++;
            }
            skipA += num;
        }

        if (j < n && isdigit(abbr2[j])) {
            int num = 0;
            if (abbr2[j] == '0') {
                return false;
            }
            while (j < n && isdigit(abbr2[j])) {
                num = num * 10 + (abbr2[j] - '0');
                j++;
            }
            skipB += num;
        }

        if (skipA > 0 && skipB > 0) {
            skipA -= min(skipA, skipB);
            skipB -= min(skipA, skipB);
        }
        if (skipA > 0) {
            j += skipA;
            if (j >= n) {
                return false;
            }
            skipA = 0;
        }
        if (skipB > 0) {
            i += skipB;
            if (i >= m) {
                return false;
            }
            skipB = 0;
        }

        if (abbr1[i] != abbr2[j]) {
            return false;
        }
        i++, j++;
    }
    return i == m && j == n && skipA == 0 && skipB == 0;
}

vector<string> minimumWindowSubstringVariation(vector<string> sentence, vector<string> words) {
    int n = sentence.size();
    unordered_map<string, int> word_freq;
    for (string word : words) {
        word_freq[word]++;
    }
    unordered_map<string, int> sentence_freq;
    int l = 0;
    int formed = 0;
    int required = word_freq.size();
    int res = INT_MAX;
    int start = 0;
    for (int r = 0; r < n; r++) {
        string word = sentence[r];
        sentence_freq[word]++;
        if (word_freq.count(word) && word_freq[word] == sentence_freq[word]) {
            formed++;
        }
        while (l < n && formed == required) {
            string to_remove = sentence[l];
            int cur_size = r - l + 1;
            if (cur_size < res) {
                res = cur_size;
                start = l;
            }
            sentence_freq[to_remove]--;
            if (word_freq.count(to_remove) && sentence_freq[to_remove] < word_freq[to_remove]) {
                formed--;
            }
            l++;
        }
    }
    vector<string> result;
    if (res != INT_MAX) {
        for (int i = 0; i < res; i++) {
            result.push_back(sentence[start + i]);
        }
    }
    return result;
}

string minimumWindowSubstringVariation2(string s, vector<char> targetVec) {
    unordered_set<char> targetSet(targetVec.begin(), targetVec.end());
    unordered_set<char> windowSet;

    int required = targetSet.size();
    int matched = 0;
    int l = 0, r = 0;
    int n = s.size();

    int start = -1, res = INT_MAX;
    for (int r = 0; r < n; r++) {
        char ch = s[r];
        while (windowSet.count(ch)) {
            windowSet.erase(s[l]);
            if (targetSet.count(s[l])) {
                matched--;
            }
            l++;
        }

        windowSet.insert(ch);
        if (targetSet.count(ch)) {
            matched++;
        }
        while (matched == required) {
            if (r - l + 1 < res) {
                res = r - l + 1;
                start = l;
            }
            char toRemove = s[l];
            windowSet.erase(toRemove);
            if (targetSet.count(toRemove)) {
                matched--;
            }
            l++;
        }
    }
    return res == INT_MAX ? "" : s.substr(start, res);
}

void testStringView(string_view s) {
    string_view read_only = "immutable";
    string editable(read_only);
    editable[0] = 'I';
}

// LC 1762
vector<int> oceanView(vector<int> heights) {
    int n = heights.size();
    if (n == 1) {
        return {0};
    }
    int left = 0, right = n - 1;
    vector<int> leftView;
    vector<int> rightView;
    leftView.push_back(left);
    rightView.push_back(right);
    int leftMax = heights[left];
    int rightMax = heights[right];
    while (left < right) {
        if (leftMax < rightMax) {
            left++;
            if (heights[left] > leftMax) {
                leftView.push_back(left);
                leftMax = left;
            }
        } else {
            right--;
            if (heights[right] > rightMax) {
                rightView.push_back(right);
                rightMax = right;
            }
        }
    }
    leftView.insert(leftView.end(), rightView.rbegin(), rightView.rend());
    return leftView;
}

// -------------------- LC 636 - Exclusive time of functions ---------------------------

struct LogEntry {
    string functionId;
    int timestamp;
    char type;

    LogEntry(string id, int timestamp, char type) : functionId(id), timestamp(timestamp), type(type) {}
};

vector<pair<string, int>> exclusiveTimes(vector<LogEntry> logTimes) {
    int n = logTimes.size();
    int prevTime = 0;
    stack<string> stk;
    unordered_map<string, int> executionTimes;
    for (int i = 0; i < n; i++) {
        string id = logTimes[i].functionId;
        int timestamp = logTimes[i].timestamp;
        char type = logTimes[i].type;

        if (type == 'b') {
            if (!stk.empty()) {
                executionTimes[stk.top()] += timestamp - prevTime;
            }
            prevTime = timestamp;
            stk.push(id);
        } else {
            executionTimes[stk.top()] += timestamp - prevTime;
            stk.pop();
            prevTime = timestamp;
        }
    }
    vector<pair<string, int>> result;
    for (auto &[id, time] : executionTimes) {
        result.push_back({id, time});
    }
    return result;
}

// ---------------LC 1091 - variant (return the shortest path)--------------------------

vector<pair<int, int>> shortestPath(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    using pii = pair<int, int>;

    vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    queue<pii> q;
    q.push({0, 0});
    map<pair<int, int>, pair<int, int>> parent;

    parent[{0, 0}] = {-1, -1};
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) {
                vector<pair<int, int>> path;
                pair<int, int> curr = {x, y};
                while (curr.first != -1) {
                    path.push_back(curr);
                    curr = parent[curr];
                }
                reverse(path.begin(), path.end());
                return path;
            }

            for (auto &offset : direction) {
                int nx = x + offset[0];
                int ny = y + offset[1];

                if (x < 0 || x > m || y < 0 || y > m) {
                    continue;
                }
                if (mat[nx][ny] == 1) {
                    continue;
                }
                if (parent.count({nx, ny})) {
                    continue;
                }
                parent[{nx, ny}] = {x, y};
            }
        }
    }
    return {};
}

// ---------------LC 1091 - variant (return any path)--------------------------

bool anyPathDFS(int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &vis, vector<pair<int, int>> &path,
                vector<vector<int>> &direction) {
    path.push_back({x, y});
    vis[x][y] = true;

    if (x == mat.size() - 1 && y == mat[0].size() - 1) {
        return true;
    }

    for (auto &offset : direction) {
        int nx = x + offset[0];
        int ny = y + offset[1];

        // ❗ Correct bounds check
        if (nx < 0 || ny < 0 || nx >= mat.size() || ny >= mat[0].size()) {
            continue;
        }

        if (vis[nx][ny] || mat[nx][ny] == 1) {
            continue;
        }

        if (anyPathDFS(nx, ny, mat, vis, path, direction)) {
            return true;
        }
    }

    path.pop_back();  // backtrack
    return false;
}

vector<pair<int, int>> anyPathUsingDFS(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> path;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> direction = {
        {-1, 0},  // up
        {1, 0},   // down
        {0, -1},  // left
        {0, 1}    // right
    };
    anyPathDFS(0, 0, mat, visited, path, direction);
    return path;
}

// ---------------LC 1004 - variant (max consecutive ones)--------------------------

// ---------------LC778 Swim in Rising Water - Variant------------------------------

vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isSafe(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

bool canReachEnd(int x, int y, vector<vector<int>> &grid, int waterLevel, vector<vector<bool>> &vis) {
    if (x == grid.size() - 1 && y == grid[0].size() - 1) {
        return true;
    }
    vis[x][y] = true;
    for (auto &offset : direction) {
        int nx = x + offset[0];
        int ny = y + offset[1];
        if (isSafe(nx, ny, grid.size(), grid[0].size()) && !vis[nx][ny] && waterLevel < grid[nx][ny]) {
            if (canReachEnd(nx, ny, grid, waterLevel, vis)) {
                return true;
            }
        }
    }
    return false;
}

int minWaterLevel(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    int low = 0;
    int high = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            high = max(high, grid[i][j]);
        }
    }
    high += 1;
    vector<vector<bool>> vis;
    while (low < high) {
        int mid = low + (high - low) / 2;
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        if (canReachEnd(0, 0, grid, mid, vis)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

// ---------------LC896. Monotonic Array - Variant------------------------------

enum Direction { UNKNOWN = -1, DEC = 0, INC = 1, FLAT = 2 };

int countMonotonicSequences(const vector<int> &nums) {
    if (nums.size() <= 1)
        return 0;

    int count = (nums[0] != nums[1]) ? 1 : 0;
    Direction dir = UNKNOWN;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            if (dir == DEC || dir == FLAT) {
                count++;
            }
            dir = INC;
        } else if (nums[i] < nums[i - 1]) {
            if (dir == INC || dir == FLAT) {
                count++;
            }
            dir = DEC;
        } else {  // nums[i] == nums[i - 1]
            if (dir != FLAT) {
                count++;
                dir = FLAT;
            }
        }
    }

    return count;
}

int maxLength(string s1, string s2) {
    unordered_set<char> uset(s2.begin(), s2.end());
    int i;
    for (i = 0; i < s1.size(); i++) {
        if (!uset.count(s1[i])) {
            return i;
        }
    }
    return i;
}

// ---------------Sliding window variation------------------------------

string slidingWindowVariation(string input, string match) {
    unordered_set<char> matchSet(match.begin(), match.end());
    int required = matchSet.size();
    int res = INT_MAX, start = INT_MAX;
    int formed = 0;
    unordered_map<char, int> inputMap;
    int l = 0;
    for (int r = 0; r < input.size(); r++) {
        char ch = input[r];
        if (matchSet.count(ch) && !inputMap.count(ch)) {
            formed++;
        }
        inputMap[ch]++;
        while (formed == required) {
            if (r - l + 1 < res) {
                res = r - l + 1;
                start = l;
            }
            char toRemove = input[l];
            inputMap[toRemove]--;
            if (matchSet.count(toRemove) && inputMap[toRemove] == 0) {
                formed--;
            }
            l++;
        }
    }
    return res == INT_MAX ? "" : input.substr(start, res);
}

// ---------------LC 721 - Accounts Merge Variation ------------------------------

void dfs(string email, string id, unordered_set<string> &visited, unordered_map<string, string> &emailToId,
         unordered_map<string, vector<string>> &adj) {
    emailToId[email] = id;
    visited.insert(email);
    for (auto relatedEmail : adj[email]) {
        if (!visited.count(relatedEmail)) {
            dfs(relatedEmail, id, visited, emailToId, adj);
        }
    }
}

vector<vector<string>> accountsMerge(unordered_map<string, vector<string>> accounts) {
    unordered_map<string, vector<string>> adj;
    for (auto [id, emails] : accounts) {
        string firstEmail = emails[0];
        for (int i = 1; i < emails.size(); i++) {
            adj[firstEmail].push_back(emails[i]);
            adj[emails[i]].push_back(firstEmail);
        }
    }

    unordered_set<string> visited;
    unordered_map<string, vector<string>> result;
    unordered_map<string, string> emailToId;

    for (auto [id, emails] : accounts) {
        string firstEmail = emails[0];
        if (visited.count(firstEmail)) {
            string sameId = emailToId[firstEmail];
            result[sameId].push_back(id);
        } else {
            result[id] = {id};
            dfs(firstEmail, id, visited, emailToId, adj);
        }
    }
    vector<vector<string>> resultV2;
    for (auto [sameId, allIds] : result) {
        resultV2.push_back(allIds);
    }
    return resultV2;
}

vector<int> randomPickIndexVariation(vector<int> nums, int k) {
    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = nums[i];
    }
    for (int i = k; i < nums.size(); i++) {
        int n = i + 1;
        int r = rand() % n;
        if (r < k) {
            result[r] = nums[i];
        }
    }
    return result;
}

// VARIANT: What if you had to use reservoir sampling to pick an index of the maximum value in the array?
int randomPickIndex_second_variant_398(vector<int> &nums) {
    int max_number = INT_MIN;
    int picked_index = -1;
    int n = 0;
    for (int i = 0; i < nums.size(); i++) {
        int curr_num = nums[i];
        if (curr_num < max_number)
            continue;

        if (curr_num > max_number) {
            max_number = curr_num;
            picked_index = i;
            n = 1;
        } else if (curr_num == max_number) {
            n++;
            int r = rand() % n;
            if (r == 0) {
                picked_index = i;
            }
        }
    }
    return picked_index;
}

// ---------------LC 34 - Find count of unique elements in sorted array ------------------------------

int findLastPos(vector<int> &nums, int low, int high, int target) {
    int lastPos = low;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            lastPos = mid;
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return lastPos;
}

int countOfUniques(vector<int> nums) {
    int i = 0;
    int n = nums.size();
    int count = 0;
    while (i < n) {
        int low = i;
        int high = n - 1;
        int lastPos = findLastPos(nums, low, high, nums[i]);
        // int lastPos = upper_bound(nums.begin() + low, nums.end(), nums[i]) - nums.begin();
        count++;
        i = lastPos + 1;
    }
    return count;
}

// ---------------LC 121 - Best time to buy flight tickets ------------------------------

int minCost(vector<int> dep, vector<int> arr) {
    int n = dep.size();
    int result = INT_MAX;
    int minArrivalCost = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = min(result, dep[i] + minArrivalCost);
        minArrivalCost = min(minArrivalCost, arr[i]);
    }
    return result;
}

// ---------------LC 1047 - Remove all adjacents variation ------------------------------

string removeDuplicates(string s) {
    string ans = "";
    int i = 0;
    int n = s.size();
    while (i < n) {
        if (!ans.empty() && s[i] == ans.back()) {
            while (i < n && s[i] == ans.back()) {
                i++;
            }
            ans.pop_back();
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }
    return ans;
}

// ---------------LC 162 - Find valley element ------------------------------

int findValleyElement(vector<int> arr) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid] < arr[mid - 1]) && (mid == n - 1 || arr[mid] < arr[mid + 1])) {
            return mid;
        } else if (arr[mid] > arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// ---------------LC 56 - Merge Intervals variation ------------------------------

vector<vector<int>> mergedIntervals(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> final;
    int m = arr1.size(), n = arr2.size();
    int i = 0, j = 0;

    // Handle empty cases
    if (m == 0)
        return arr2;
    if (n == 0)
        return arr1;

    auto appendOrMerge = [&](const vector<int> &interval) {
        if (final.empty() || final.back()[1] < interval[0]) {
            final.push_back(interval);
        } else {
            final.back()[1] = max(final.back()[1], interval[1]);
        }
    };

    // Merge both arrays
    while (i < m && j < n) {
        if (arr1[i][0] <= arr2[j][0]) {
            appendOrMerge(arr1[i]);
            i++;
        } else {
            appendOrMerge(arr2[j]);
            j++;
        }
    }
    // Add remaining from arr1
    while (i < m) {
        appendOrMerge(arr1[i]);
        i++;
    }
    // Add remaining from arr2
    while (j < n) {
        appendOrMerge(arr2[j]);
        j++;
    }
    return final;
}

vector<int> oceanViewVariant(vector<int> buildings) {
    int n = buildings.size();
    if (n == 1) {
        return {0};
    }
    int left = 0, right = n - 1;
    vector<int> leftView{0};
    vector<int> rightView{n - 1};
    int lMax = buildings[left];
    int rMax = buildings[right];
    while (left < right) {
        if (lMax < rMax) {
            left++;
            if (buildings[left] > lMax && left < right) {
                leftView.push_back(left);
                lMax = buildings[left];
            }
        } else {
            right--;
            if (buildings[right] > rMax && left < right) {
                rightView.push_back(right);
                rMax = buildings[right];
            }
        }
    }
    leftView.insert(leftView.end(), rightView.rbegin(), rightView.rend());
    return leftView;
}

// ---------------LC 528 - Random Pick with Weight variation ------------------------------

string pickRandomPersonForAB(vector<pair<string, int>> city) {
    vector<pair<string, int>> prefix;
    int sum = 0;
    for (int i = 0; i < city.size(); i++) {
        sum += city[i].second;
        prefix.push_back({city[i].first, sum});
    }

    int person = rand() % sum;
    int low = 0, high = prefix.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (prefix[mid].second > person) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return prefix[high].first;
}

// ---------------LC 199 - Left view and right view in same traversal ------------------------------

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, int currDepth, vector<int> &leftView, vector<int> &rightView) {
    if (!root) {
        return;
    }

    // First time visiting this level from left side
    if (currDepth == (int)leftView.size()) {
        leftView.push_back(root->val);
    }

    // First time visiting this level from right side
    if (currDepth == (int)rightView.size()) {
        rightView.push_back(root->val);
    } else {
        rightView[currDepth] = root->val;  // Update with the rightmost node at this depth
    }

    dfs(root->left, currDepth + 1, leftView, rightView);
    dfs(root->right, currDepth + 1, leftView, rightView);
}

// ---------------LC 71 - Simplify Path variation ------------------------------

string simplifyPath(string cwd, string cd) {
    if (cd.empty()) {
        return cwd;
    }
    if (cwd.empty() || cd[0] == '/') {
        cwd = "";
    }
    stringstream cwd_ss(cwd);
    string token;
    vector<string> tokens;
    while (getline(cwd_ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue;
        }
        if (token == "..") {
            if (!tokens.empty()) {
                tokens.pop_back();
            }
            continue;
        }
        tokens.push_back(token);
    }

    stringstream cd_ss(cd);
    while (getline(cd_ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue;
        }
        if (token == "..") {
            if (!tokens.empty()) {
                tokens.pop_back();
            }
            continue;
        }
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        return "/";
    }

    string result = "";
    for (string &dir : tokens) {
        result += "/";
        result += dir;
    }
    return result;
}

// ---------------LC 776 - Toeplitx matrix ------------------------------

bool isToeplitz(vector<int> arr, int m, int n) {
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int currItem = arr[n * i + j];
            int prevItem = arr[n * (i - 1) + (j - 1)];
            if (currItem != prevItem) {
                return false;
            }
        }
    }
    return true;
}

// ---------------LC 347 - Top K frequent elements ------------------------------

vector<int> topKFrequent(vector<int> arr, int k) {
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    using pii = pair<int, int>;
    auto cmp = [](pii &a, pii &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> maxHeap(cmp);
    for (auto [element, count] : freq) {
        if (maxHeap.size() < k) {
            maxHeap.push({element, count});
        } else {
            if (count > maxHeap.top().second) {
                maxHeap.pop();
                maxHeap.push({element, count});
            }
        }
    }
    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().first);
        maxHeap.pop();
    }
    return result;
}

int friendRequests(vector<int> ages) {
    sort(ages.begin(), ages.end());
    int requests = 0;
    for (auto age : ages) {
        int maxAge = age;
        int minAge = ceil(age / 2.0) + 7;

        if (age > 100) {
            minAge = max(minAge, 100);
        }

        auto left = lower_bound(ages.begin(), ages.end(), minAge);
        auto right = upper_bound(ages.begin(), ages.end(), maxAge);

        int count = right - left;

        if (age >= minAge && age <= maxAge) {
            count -= 1;
        }
        requests += count;
    }
    return requests;
}

int main() {
    srand(time(0));
    std::cout << "RAND_MAX = " << RAND_MAX << "\n";
    std::cout << "RAND_MAX = " << INT_MAX << "\n";
    return 0;
}
