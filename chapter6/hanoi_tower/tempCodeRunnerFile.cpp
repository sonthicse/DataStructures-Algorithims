
// Explicit instantiation for common types
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;

// Explicit instantiation of operator<< for common types
template std::ostream& operator<<(std::ostream&, const Stack<int>&);
template std::ostream& operator<<(std::ostream&, const Stack<double>&);
template std::ostream& operator<<(std::ostream&, const Stack<std::string>&);