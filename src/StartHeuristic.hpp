// --------------------------------------------------------------------------
//                   deregnet -- find deregulated pathways
// --------------------------------------------------------------------------
// Copyright Sebastian Winkler --- Eberhard Karls University Tuebingen, 2020
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Sebastian Winkler $
// $Authors: Sebastian Winkler $
// --------------------------------------------------------------------------
//

#ifndef START_HEURISTIC_H
#define START_HEURISTIC_H

#include <set>
#include <utility>

#include "usinglemon.hpp"
#include "DeregnetStartHeuristic.hpp"

namespace deregnet {

/**
 * @brief Implementation of heuristic start solution algorithm for absolute optimal DeRegNet algorithm
 */
class StartHeuristic : public DeregnetStartHeuristic {

  private:

    int size;   ///< Size of the current subgraph

  public:

    /**
     * @brief Constructor
     *
     * @param xgraph
     * @param xscore
     * @param root
     * @param exclude
     * @param receptors
     * @param xcmp
     * @param xsize
     */
    StartHeuristic(Graph* xgraph,
                   NodeMap<double>* xscore,
                   Node* root,
                   std::set<Node>* exclude,
                   std::set<Node>* receptors,
                   std::function<bool(double, double)> xcmp,
                   int xsize);

  private:

    virtual Node* get_best_root() override;
    virtual bool search_further() override;
    virtual bool feasible_node(Node* node) override;

};

}    //    namespace deregnet

#endif    //    START_HEURISTIC
