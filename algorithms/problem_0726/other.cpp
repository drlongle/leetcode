class Solution {

    std::pair<std::string, int> read_atom(const std::string& s, int start)
    {
        int i = start;
        while(i < s.size())
        {
            const char& c = s[i];
            if(!std::isalpha(c))
                break;

            // reading one character atoms
            if(i != start and std::isupper(c))
                break;
            i++;
        }

        return {s.substr(start, i-start), i};
    }

    std::pair<int, int> read_multiplicity(const std::string& s, int start)
    {
        int i = start;
        while(i < s.size() and std::isdigit(s[i]))
            i++;

        if(i != start)
            return { std::stoi(s.substr(start, i-start)), i};
        else
            return {1, i};
    }

    auto order_atoms(std::stack<std::pair<std::string, int>>& stack)
    {
        std::map<std::string, int> atoms_with_count{};
        while(!stack.empty())
        {
            auto& top = stack.top();
            // omitting the dummy element
            if(top.first != "(")
            {
                atoms_with_count[std::move(top.first)] += top.second;
            }
            stack.pop();
        }

        return atoms_with_count;
    }

    auto resulted_string(std::map<std::string, int> ordered_atoms)
    {
        std::string result{};
        for(auto&& p : ordered_atoms)
        {
            result.append(std::move(p.first));
            // no need to print the count 1
            if(p.second != 1)
                result.append(std::to_string(p.second));
        }

        return result;
    }

public:
    std::string countOfAtoms(std::string formula) {
        std::stack<std::pair<std::string, int>> stack{};
        int i = 0;

        while(i < formula.size())
        {
            if(formula[i] == '(')
            {
                // dummy element
                stack.push({"(", 0});

                auto [atom, new_start_after_atom] = read_atom(formula, i+1);
                auto [multiplicity, new_start_after_multiplicity] = read_multiplicity(formula, new_start_after_atom);

                // if the input contains "((..."
                if(atom != "")
                    stack.push({std::move(atom), multiplicity});

                i = new_start_after_multiplicity;
            }
            else if(formula[i] == ')')
            {
                auto [multiplicity, new_start] = read_multiplicity(formula, i+1);
                i = new_start;

                // processing/multiplying elements in the stack
                if(multiplicity != 1)
                {
                    std::stack<std::pair<std::string, int>> auxiliary_stack{};
                    while(stack.top().first != "(")
                    {
                        auto& [atom, current_number] = stack.top();
                        auxiliary_stack.push({std::move(atom), (multiplicity * current_number)});

                        stack.pop();
                    }

                    // pop out '('
                    stack.pop();

                    // moving back the processed elements
                    while(!auxiliary_stack.empty())
                    {
                        stack.push(std::move(auxiliary_stack.top()));
                        auxiliary_stack.pop();
                    }
                }
            }
            else
            {
                auto [atom, new_start_after_atom] = read_atom(formula, i);
                auto [multiplicity, new_start_after_multiplicity] = read_multiplicity(formula, new_start_after_atom);

                stack.push({std::move(atom), multiplicity});

                i = new_start_after_multiplicity;
            }
        }

        auto ordered_atoms = order_atoms(stack);

        return resulted_string(ordered_atoms);
    }
};
