%--------------------------------------------------------------------------
%BRIGHTON S CHIKOMO
%ENR PRACTICAL PRACTICAL 1 FOR TOPIC 1
%MINIMUM COST SOLUTION 
%LAST EDITED: 10/09/2019    TIME:0133hrs
%--------------------------------------------------------------------------

%variables
cf = 1.2; 
a = 0.246; 
b = 0.1; 

%--------- THE HESSIAN MATRIX FORMULATION------------

%Big matrix 96*96
big_H = zeros(96);

%creating small matrix to fit in a big matrix
sm1_H = 2*cf*a*ones(1,24);
small_H = diag(sm1_H);


% Specify upper left row, column of where 
% we'd like to paste the small matrix.
row1_H = 1;
column1_H = 1;
% Determine lower right location.
row2_H = 24;
column2_H = 24;


% It will fit, so paste it.
big_H(row1_H:row2_H, column1_H:column2_H) = small_H;
H = big_H;
%---------------END OF HESSIAM MATRIX FORMULATION----------------

%--------- THE f MATRIX FORMULATION------------


big_f = zeros(96,1);
%creating small matrix to fit in a big matrix
small_f = b*cf*ones(24,1);


% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_f = 1;
column1_f = 1;

% Determine lower right location.
row2_f = 24;
column2_f = 1;

% It will fit, so paste it.
big_f(row1_f:row2_f, column1_f:column2_f) = small_f;
f = big_f;

%---------------END OF f MATRIX FORMULATION----------------


%--------- THE Aeq MATRIX FORMULATION------------

big_Aeq = zeros(24,96);
%creating small matrix to fit in a big matrix
sm_Aeq = ones(1,24);
small_Aeq = diag(sm_Aeq);

% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_Aeq1 = 1;
column1_Aeq1 = 1;
% Determine lower right location.
row2_Aeq1 = 24
column2_Aeq1 = 24

% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_Aeq2 = 1;
column1_Aeq2 = 25;
% Determine lower right location.
row2_Aeq2 = 24
column2_Aeq2 = 48

% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_Aeq3 = 1;
column1_Aeq3 = 73;
% Determine lower right location.
row2_Aeq3 = 24
column2_Aeq3 = 96

% It will fit, so paste it.
big_Aeq(row1_Aeq1:row2_Aeq1, column1_Aeq1:column2_Aeq1) = small_Aeq;
big_Aeq(row1_Aeq2:row2_Aeq2, column1_Aeq2:column2_Aeq2) = small_Aeq;
big_Aeq(row1_Aeq3:row2_Aeq3, column1_Aeq3:column2_Aeq3) = small_Aeq;
Aeq = big_Aeq;
%---------------END OF f MATRIX FORMULATION----------------

%--------- THE A MATRIX FORMULATION------------

big_A = zeros(26,96);
%creating small matrix to fit in a big matrix
sm_A1 = ones(1,24);
small_A1 = diag(sm_A1);

sm_A2 = -1*sm_A1;
sm_A3 = 0.85*ones(1,24);
sm_A4 = -0.85*ones(1,24);



% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_A2 = 1;
column1_A2 = 25;
% Determine lower right location.
row2_A2 = 24;
column2_A2 = 48;

% Specify upper left row, column of where
% we'd like to paste the small matrix.
row1_A3 = 1;
column1_A3 = 49;
% Determine lower right location.
row2_A3 = 24;
column2_A3 = 72;

%matrix fitting
row1_A4 = 25;
column1_A4 = 49;
row2_A4 = 25;
column2_A4 = 72;

%matrix fitting
row1_A5 = 25;
column1_A5 = 73;
row2_A5 = 25;
column2_A5 = 96;

%matrix fitting
row1_A6 = 26;

% It will fit, so paste it.
big_A(row1_A2:row2_A2, column1_A2:column2_A2) = small_A1;
big_A(row1_A3:row2_A3, column1_A3:column2_A3) = small_A1;
big_A(row1_A4:row2_A4, column1_A4:column2_A4) = sm_A3;
big_A(row1_A5:row2_A5, column1_A5:column2_A5) = sm_A2;
big_A(row1_A6:row1_A6, column1_A4:column2_A4) = sm_A4;
big_A(row1_A6:row1_A6, column1_A5:column2_A5) = sm_A1;
A = big_A;
%---------------END OF A MATRIX FORMULATION----------------


%--------- THE b_eq MATRIX FORMULATION------------

%winter weekend b_eq
beq =[1.5; 1.5; 1.5;1.5; 1.5; 1.65;
      1.65;1.35; 1.35; 3.0; 3.0; 1.95
      1.95; 1.95; 1.95; 1.95; 1.65; 1.65
      3.25; 3.25; 2.31; 2.15; 2.15; 1.35];
%---------------END OF b_eq MATRIX FORMULATION--------------


%--------- B MATRIX FORMULATION------------

B1 = [0; 0; 0; 0; 0; 0.099289033;
    0.978821256; 1.502028173; 2.042584404; 3.577165653; 3.444461772;
    4.434166272; 4.241990345; 3.825667164; 3.991322068; 2.31155128;
    0.945992816; 0.286574412; 0.065641571; 0.000662658;
    0; 0; 0.000181151; 0; 27.25; 0];

B = [0; 0; 0; 0; 0; 0.099289033;
    0.978821256; 1.502028173; 2.042584404; 3.577165653;
    3.444461772; 4.434166272; 4.241990345; 3.825667164;
    3.991322068; 2.31155128; 0.945992816; 0.286574412;
    0.065641571; 0.000662658; 0; 0; 0.000181151; 0 ;27.25; 0];
%---------------END OF B MATRIX FORMULATION----------------

%--------- BOUNDARY MATRIX FORMULATION------------

%Bounderies
%1) lower boundary
lb = zeros(96,1);

%2) upper boundary
UB_big = zeros(96,1);
UB_sm1 = 5*ones(24,1);
UB_sm2 = 4*ones(48,1);
UB_sm3 = 54.5*ones(24,1);

row1_ub1 = 1;
col_ub = 1;
row1_ub2 = 24;

row2_ub1 = 25;
row2_ub2 = 72;

row3_ub1 = 73;
row3_ub2 = 96;

UB_big( row1_ub1:row1_ub2, col_ub:col_ub)= UB_sm1; 
UB_big( row2_ub1:row2_ub2, col_ub:col_ub)= UB_sm2; 
UB_big( row3_ub1:row3_ub2, col_ub:col_ub)= UB_sm3; 
ub = UB_big;
%---------END OF BOUNDARY MATRIX FORMULATION------------

x0 = zeros(96,1);



%-----------------MAIN CODE TO PLOT--------------------------
[X,FVAL]= my_qdprog(H, f, A, B, Aeq, beq, lb, ub, x0)