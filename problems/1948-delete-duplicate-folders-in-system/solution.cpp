// 1948. Delete Duplicate Folders in System [Hard]
// https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Language: C++ | Runtime: 186 ms | Memory: 284.8 MB

class Solution {
public:
    struct Trie {
        string name;
        unordered_map<string, Trie*> children;
        bool deleted = false;
        Trie(string name = "") : name(name) {}
    };

    Trie* root = new Trie();

    void insert(const vector<string>& path) {
        Trie* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new Trie(folder);
            node = node->children[folder];
        }
    }

    string serialize(Trie* node, unordered_map<string, vector<Trie*>>& seen) {
        if (node->children.empty()) return "";

        vector<string> serialized;
        for (auto& [name, child] : node->children) {
            serialized.push_back(serialize(child, seen) + "#" + name);
        }

        sort(serialized.begin(), serialized.end());

        string key;
        for (string& s : serialized) key += "(" + s + ")";
        seen[key].push_back(node);
        return key;
    }

    void collect(Trie* node, vector<string>& path, vector<vector<string>>& result) {
        if (node->deleted) return;

        if (!node->name.empty()) path.push_back(node->name);
        if (!path.empty()) result.push_back(path);

        for (auto& [name, child] : node->children) {
            collect(child, path, result);
        }

        if (!node->name.empty()) path.pop_back();
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (const auto& path : paths) insert(path);

        unordered_map<string, vector<Trie*>> seen;
        serialize(root, seen);

        for (auto& [key, nodes] : seen) {
            if (nodes.size() > 1) {
                for (Trie* node : nodes) node->deleted = true;
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        for (auto& [_, child] : root->children) {
            collect(child, path, result);
        }

        return result;
    }
};
