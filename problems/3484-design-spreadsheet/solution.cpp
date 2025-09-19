// 3484. Design Spreadsheet [Medium]
// https://leetcode.com/problems/design-spreadsheet/
// Language: C++ | Runtime: 58 ms | Memory: 124.1 MB

class Spreadsheet {
private:
    int rows;
    // Store cell values in a map (only store non-zero cells to save space)
    unordered_map<string, int> table;

    // Check if token is a number or a cell reference
    bool isNumber(const string &s) {
        return isdigit(s[0]);
    }

    // Get value of token (cell reference or number)
    int getTokenValue(const string &token) {
        if (isNumber(token)) {
            return stoi(token);
        } else {
            if (table.find(token) != table.end()) {
                return table[token];
            }
            return 0; // default value for unset cells
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
    }

    void setCell(string cell, int value) {
        table[cell] = value;
    }

    void resetCell(string cell) {
        table[cell] = 0;
    }

    int getValue(string formula) {
        // formula looks like "=X+Y"
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');

        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getTokenValue(left);
        int val2 = getTokenValue(right);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
