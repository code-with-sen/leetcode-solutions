// 3408. Design Task Manager [Medium]
// https://leetcode.com/problems/design-task-manager/
// Language: C++ | Runtime: 301 ms | Memory: 370.1 MB

class TaskManager {
    struct Task {
        int userId;
        int taskId;
        int priority;
        Task() {}
        Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
        bool operator<(const Task& other) const {
            if (priority == other.priority) return taskId > other.taskId;
            return priority > other.priority;
        }
    };

    unordered_map<int, Task> taskMap; // taskId -> Task
    set<Task> taskSet;                // ordered tasks

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task task(userId, taskId, priority);
        taskMap[taskId] = task;
        taskSet.insert(task);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task old = it->second;
        taskSet.erase(old);
        Task updated(old.userId, old.taskId, newPriority);
        taskMap[taskId] = updated;
        taskSet.insert(updated);
    }
    
    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task t = it->second;
        taskSet.erase(t);
        taskMap.erase(it);
    }
    
    int execTop() {
        if (taskSet.empty()) return -1;
        Task top = *taskSet.begin();
        taskSet.erase(taskSet.begin());
        taskMap.erase(top.taskId);
        return top.userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
