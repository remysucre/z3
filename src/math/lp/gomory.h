/*++
Copyright (c) 2017 Microsoft Corporation

Module Name:

    <name>

Abstract:

    <abstract>

Author:
    Nikolaj Bjorner (nbjorner)
    Lev Nachmanson (levnach)

Revision History:
--*/
#pragma once
#include "math/lp/lar_term.h"
#include "math/lp/lia_move.h"
#include "math/lp/explanation.h"
#include "math/lp/static_matrix.h"

namespace lp {
    struct cut_result;
    class int_solver;
    class lar_solver;
    class gomory {
        class int_solver& lia;
        class lar_solver& lra;
        unsigned_vector gomory_select_int_infeasible_vars(unsigned num_cuts);
        bool is_gomory_cut_target(lpvar j); 
        bool row_invariant(const row_strip<mpq>&) const;
        void add_big_cuts(const vector<cut_result>&);
        void add_cut(const cut_result&);
        bool check_feasible();
        mpq get_gomory_score(lpvar) const;
    public:
        lia_move get_gomory_cuts(unsigned num_cuts);
        gomory(int_solver& lia);
    };
}
