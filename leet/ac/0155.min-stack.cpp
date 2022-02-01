/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
  private:
    stack<int> st;
    multiset<int> ms;

  public:
    MinStack() {}

    void push(int x) {
        st.push(x);
        ms.insert(x);
    }

    void pop() {
        int t = st.top();
        int c = ms.count(t) - 1;
        st.pop();
        ms.erase(t);
        while (c--) {
            ms.insert(t);
        }
    }

    int top() { return st.top(); }

    int getMin() { return *ms.begin(); }
};
