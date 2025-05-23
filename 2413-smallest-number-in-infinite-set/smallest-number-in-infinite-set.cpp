class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> st;
    SmallestInfiniteSet() {

        for (int i = 1; i <= 1000; i++) {
            q.push(i);
            st.insert(i);
        }
    }

    int popSmallest() {
        if (!q.empty()) {
            int smallest = q.top();
            st.erase(smallest); 
            q.pop();
            return smallest;
        }
        return -1;
    }

    void addBack(int num) {
        if (st.count(num) == 0) {
            q.push(num);
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */