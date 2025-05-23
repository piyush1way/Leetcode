class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> st;
    int next;
    SmallestInfiniteSet() {
        next = 1;
    }

    int popSmallest() {
        if (!q.empty()) {
            int smallest = q.top();
            st.erase(smallest); 
            q.pop();
            return smallest;
        }
        return next++;
    }

    void addBack(int num) {
        if(num<next && st.find(num)==st.end()){
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