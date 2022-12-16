#include "priority_queue.h"

int main() {
    // TODO(student): write at least 1000 lines of test
    std::cout << "SELECTION PROBLEM" << std::endl;
std::cout << "make a priority queue from N = 168 elements in O(N) time" << std::endl;
std::vector<int> values{509, 887, 53, 739, 491, 307, 727, 223, 919, 263, 983, 7, 809, 353, 659, 769, 173, 431, 619, 139, 2, 3, 181, 23, 283, 617, 463, 757, 89, 541, 997, 743, 907, 13, 337, 349, 523, 857, 97, 827, 661, 67, 373, 59, 11, 277, 379, 19, 941, 607, 367, 101, 457, 929, 599, 971, 967, 647, 71, 991, 211, 467, 881, 137, 311, 673, 197, 179, 859, 239, 233, 631, 449, 281, 499, 269, 877, 421, 419, 613, 593, 383, 937, 569, 487, 839, 479, 461, 683, 653, 227, 61, 107, 113, 947, 191, 103, 313, 733, 151, 257, 73, 821, 547, 521, 691, 83, 823, 443, 31, 5, 643, 131, 389, 571, 163, 271, 601, 359, 199, 853, 29, 167, 557, 157, 193, 977, 37, 41, 773, 347, 709, 251, 331, 829, 503, 409, 719, 397, 241, 47, 641, 787, 863, 109, 587, 17, 751, 229, 911, 811, 317, 563, 701, 797, 953, 293, 149, 439, 127, 883, 577, 79, 433, 43, 761, 401, 677};
PriorityQueue<int> pq(values);

std::cout << "pop k = 42 = O(N / log N) elements in O(k log N) = O(N) time" << std::endl;
for (int i = 0; i < 41; i++) { pq.pop(); }
// ^^^ pops 41, top is would-be 42nd pop vvvvv
std::cout << "found k-th smallest element = " << pq.top() << " in O(N + k log N)= O(N) time" << std::endl;

std::cout << std::endl << "INTERMISSION" << std::endl;

std::cout << "empty the queue in O(1) time" << std::endl;
pq.make_empty();
    
std::cout << std::endl << "DISCRETE EVENT SIMULATION" << std::endl;
int t = 0;
size_t busy_start = 0, busy_stop = 0, busy_time = 0, wait_time = 0, cnt = 0, cust_id = 0, next = 7;
bool busy = false;
std::deque<size_t> line;
pq.push(t);
while (!pq.empty()) {
    t = pq.top();
    pq.pop();
    if (t%2) {
        // departure
        std::cout << "customer departed at time " << t << std::endl;
        cnt++;
        if (line.empty()) {
            busy = false;
            busy_stop = t;
            busy_time += busy_stop - busy_start;
        } else {
            // next in line
            int arrival_time = line.front();
            line.pop_front();
            wait_time += (t - arrival_time);
            std::cout << "next customer in line has been waiting " << (t - arrival_time) << " time units" << std::endl;
            // schedule departure at odd time (t is odd right now), >0 from now
            int service_time = 2*((next+3)%5)+2;
            pq.push(t + service_time);
            next = (next+5)%11;
        }
    } else {
        // arrival
        std::cout << "customer " << ++cust_id << " arrived at time " << t << std::endl;
        if (cust_id < 10) {
            // schedule next arrival at even time (t is even right now)
            int interarrival_time = 2*((next+3)%5)+2;
            pq.push(t + interarrival_time);
            next = (next+5)%11;
        }
        if (busy) {
               // wait in line
            line.push_back(t);
            std::cout << "  server is busy, customer must wait in line, there are " << line.size() << " in line" << std::endl;
        } else {
            // serve
            busy = true;
            busy_start = t;
            std::cout << "  service begins immediately" << std::endl;
            // schedule departure at odd time (t is even right now), >0 from now
            int service_time = 2*((next+3)%5) + 1;
            pq.push(t + service_time);
            next = (next+5)%11;
        }
    }
}
std::cout << "end of simulation\n-----------------" << std::endl;
std::cout << "served 10 customers in " << t << " time units" << std::endl;
std::cout << "server was busy for " << busy_time << " total time units" << std::endl;
std::cout << "customers waited " << wait_time << " total time units" << std::endl;

    
    return 0;
}
