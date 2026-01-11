function [x, fval] = my_qdprog(H, f, A, B, Aeq, beq, lb, ub, x0)
    %#codegen
    % Only include options supported for code generation
    opts = optimoptions('quadprog', ...
                        'Algorithm', 'active-set', ...
                        'ConstraintTolerance', 1e-6); 
    
    [x, fval] = quadprog(H, f, A, B, Aeq, beq, lb, ub, x0, opts);
end

