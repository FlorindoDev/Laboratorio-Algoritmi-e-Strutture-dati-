#include "binarytree.hpp"


namespace lasd {

    /***************************************************************************************/
    /*                                  Operatori Node                                     */
    /***************************************************************************************/

    template <typename Data>
    bool BinaryTree<Data>::Node::operator==(const Node & nod) const noexcept{
        if(nod.Element() != this->Element()) return false;

        //controllo se questo nodo ha figli
        bool FiglioDx = this->HasRightChild();
        bool FiglioSx = this->HasLeftChild(); 

        //controllo se il nodo che stiamo confrotando abbia dei figli
        bool CompareFiglioDX = nod.HasRightChild();
        bool CompareFiglioSX = nod.HasLeftChild(); 

        //controllo se i due nodi hanno lo stesso numero di figli nella stessa posizione
        bool right = (FiglioDx == CompareFiglioDX);
        bool left = (FiglioSx == CompareFiglioSX); 

        //scelata caso ricorsivo
        if(left && right ){            //se hanno i figli nella stessa posizione entro 

            if (FiglioSx && FiglioDx){          //se ho due figli li confronto entrambi
                return ((nod.LeftChild() == this->LeftChild()) && (nod.RightChild() == this->RightChild()));
            } 
            else if (FiglioSx){                 //se ho un figlo lo confronto

                return (nod.LeftChild() == this->LeftChild());

            }else if (FiglioDx){                //se ho un figlo lo confronto
                return (nod.RightChild() == this->RightChild());
            }else{
                return true;
            }
        }

        return false;
    }

    template <typename Data>
    bool BinaryTree<Data>::Node::operator!=(const Node & nod) const noexcept{
        return !(*this==nod);
    }


    /****************************************************************************************/


    /***************************************************************************************/
    /*                                  Operatori BT                                       */
    /***************************************************************************************/

    template <typename Data>
    bool BinaryTree<Data>::operator==(const BinaryTree & bt) const noexcept {
        if(this->Size() == 0 && bt.Size() == 0) return true;
        if(this->size != bt.size) return false;
        if((this->size == bt.size) && this->Size()!= 0){
           return (this->Root() == bt.Root()); 
        }
        return false;
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree & bt) const noexcept {
        return !(bt == *this);
    }

    /***************************************************************************************/
    /*                              Funzioni per la visita BT                              */
    /***************************************************************************************/

    template <typename Data>
    void BinaryTree<Data>::Traverse(TraverseFun fun) const{
        if(this->size > 0){
            this->PreOrderTraverse(fun, this->Root());
        }
        
    }

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const{
        if(this->size > 0){
            this->PreOrderTraverse(fun, this->Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const{
        if(this->size > 0){
            this->PostOrderTraverse(fun, this->Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const{
        if(this->size > 0){
            this->InOrderTraverse(fun, this->Root());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const{
        if(this->size > 0){
            this->BreadthTraverse(fun, this->Root());
        }
    }
   
    /***************************************************************************************/
    /*                              Funzioni Ausiliari BT                                  */
    /***************************************************************************************/

    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node& nod) const{

        fun(nod.Element());
        if(!(nod.IsLeaf())){
            if(nod.HasLeftChild()){
                PreOrderTraverse(fun, nod.LeftChild()); 
            }   

            if(nod.HasRightChild()){
                PreOrderTraverse(fun, nod.RightChild());
            }
            
        }
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node& nod) const{

        if(!(nod.IsLeaf())){
            if(nod.HasLeftChild()){
                PostOrderTraverse(fun, nod.LeftChild()); 
            }   

            if(nod.HasRightChild()){
                PostOrderTraverse(fun, nod.RightChild());
            }
        }

        fun(nod.Element());
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node& nod) const{

        if(!(nod.IsLeaf())){

            if(nod.HasLeftChild()){
                InOrderTraverse(fun, nod.LeftChild()); 
            }   

            fun(nod.Element());

            if(nod.HasRightChild()){
                InOrderTraverse(fun, nod.RightChild());
            }

        }else{
            fun(nod.Element());
        }
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node& nod) const{
    
        if(!(nod.IsLeaf())){
            QueueVec<const Node *> Que;
            Que.Enqueue(&nod);
            while(!(Que.Empty())){
                const Node * corr = Que.HeadNDequeue();
                if(corr->HasLeftChild()){
                    Que.Enqueue(&(corr->LeftChild()));
                }

                if(corr->HasRightChild()){
                    Que.Enqueue(&(corr->RightChild()));
                }

                fun(corr->Element());
            }
            
        }else{
            fun(nod.Element());
        }
    }

    /***************************************************************************************/
    /*                              Funzioni Visita MBT                                    */
    /***************************************************************************************/

    template <typename Data>
    void MutableBinaryTree<Data>::Map(MapFun fun) {
        if(this->size > 0){
            this->PreOrderMap(fun, this->Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
        if(this->size > 0){
            this->PreOrderMap(fun, this->Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
        if(this->size > 0){
            this->PostOrderMap(fun, this->Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
        if(this->size > 0){
            this->InOrderMap(fun, this->Root());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
        if(this->size > 0){
            this->BreadthMap(fun, this->Root());
        }
    }

    /***************************************************************************************/
    /*                              Funzioni Ausiliari MBT                                 */
    /***************************************************************************************/
    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode & nod){

        fun(nod.Element());
        if(!(nod.IsLeaf())){
            if(nod.HasLeftChild()){
                PreOrderMap(fun, nod.LeftChild()); 
            }   

            if(nod.HasRightChild()){
                PreOrderMap(fun, nod.RightChild());
            }
            
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode& nod){

        if(!(nod.IsLeaf())){
            if(nod.HasLeftChild()){
                PostOrderMap(fun, nod.LeftChild()); 
            }   

            if(nod.HasRightChild()){
                PostOrderMap(fun, nod.RightChild());
            }
        }

        fun(nod.Element());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode& nod){

        if(!(nod.IsLeaf())){

            if(nod.HasLeftChild()){
                InOrderMap(fun, nod.LeftChild()); 
            }   

            fun(nod.Element());

            if(nod.HasRightChild()){
                InOrderMap(fun, nod.RightChild());
            }

        }else{
            fun(nod.Element());
        }
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode& nod){
    
        if(!(nod.IsLeaf())){
            QueueVec<MutableNode *> Que;
            Que.Enqueue(&nod);
            while(!(Que.Empty())){
                MutableNode * corr = Que.HeadNDequeue();
                if(corr->HasLeftChild()){
                    Que.Enqueue(&(corr->LeftChild()));
                }

                if(corr->HasRightChild()){
                    Que.Enqueue(&(corr->RightChild()));
                }

                fun(corr->Element());
            }
            
        }else{
            fun(nod.Element());
        }
    }

    /***************************************************************************************/
    /*                              Costruttori e Distruttori PreBT                        */
    /***************************************************************************************/

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> & bt){
        if(bt.Size() > 0){
            corrente = &(bt.Root());
            radice = &(bt.Root());
        }
        
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> & pbtIter){
        corrente = pbtIter.corrente;
        radice = pbtIter.radice;
        Stk = pbtIter.Stk;
    
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> && pbtIter){
        std::swap(corrente, pbtIter.corrente);
        std::swap(Stk, pbtIter.Stk);
        std::swap(radice, pbtIter.radice);
        
    }


    template <typename Data>
    BTPreOrderIterator<Data>::~BTPreOrderIterator(){
        corrente = nullptr;
        Stk.Clear();
        radice = nullptr;
        //delete &Stk;
    }

    /***************************************************************************************/
    /*                              Operatori PreBT                                        */
    /***************************************************************************************/

    //Copy assignment
    template <typename Data>
    BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> & pbtIter){
        BTPreOrderIterator<Data> *tmp = new BTPreOrderIterator(pbtIter);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move assignment
    template <typename Data>
    BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> && pbtIter){
        std::swap(Stk, pbtIter.Stk);
        std::swap(corrente, pbtIter.corrente);
        std::swap(radice, pbtIter.radice);
        return *this;
    }

    //Comparison operators
    template <typename Data>
    bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> & pbtIter) const noexcept{
        if(pbtIter.Stk == this->Stk && *corrente == *(pbtIter.corrente)) return true;
        return false;
    }

    template <typename Data>
    bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> & pbtIter) const noexcept{
        return !(*this == pbtIter);
    }

    template <typename Data>
    const Data & BTPreOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
            return corrente->Element();
        }
    }

    template <typename Data>
    BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator++(){
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }

        if(corrente->HasRightChild()){
            Stk.Push(&(corrente->RightChild()));
        }

        if(corrente->HasLeftChild()){
            Stk.Push(&(corrente->LeftChild()));
        }

        if(Stk.Empty()){
            corrente = nullptr;
        }else{
            corrente = Stk.TopNPop();
        }

        return *this;

    }

    /***************************************************************************************/
    /*                                 Funzioni specifiche PreBT                           */
    /***************************************************************************************/

    template <typename Data>
    bool BTPreOrderIterator<Data>::Terminated() const noexcept{
        return corrente == nullptr;
    }

    template <typename Data>
    void BTPreOrderIterator<Data>::Reset() noexcept{

        if(radice != nullptr){
            Stk.Clear();
            corrente = radice;
        }
            
    }


    /****************************************************************************************/

    /***************************************************************************************/
    /*                            Costruttori e Distruttori MPreBT                        */
    /***************************************************************************************/

    // Specific constructors
    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data> & mbt){
        if(mbt.Size() > 0){
            this->corrente = &(mbt.Root());
            this->radice = this->corrente; 
        }
    }

    // Copy constructor
    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator & mbt){

        this->corrente = mbt.corrente;
        this->Stk = mbt.Stk;

    }

    // Move constructor
    template <typename Data>
    BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator && mbt){
        std::swap(this->corrente, mbt.corrente);
        std::swap(this->Stk, mbt.Stk);
        
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data>::~BTPreOrderMutableIterator(){
        this->corrente = nullptr;
        this->Stk.Clear();
        // delete Stk;
    }


    /***************************************************************************************/
    /*                             Operatori MPreBT                                        */
    /***************************************************************************************/
    

    //Copy
    template <typename Data>
    BTPreOrderMutableIterator<Data> & BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator & pbtIter){
        BTPreOrderMutableIterator<Data> *tmp = new BTPreOrderMutableIterator(pbtIter);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move
    template <typename Data>
    BTPreOrderMutableIterator<Data> & BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator && pbtIter){
        std::swap(this->Stk, pbtIter.Stk);
        std::swap(this->corrente, pbtIter.corrente);
        return *this;
    }

    //Comparison operators
    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data> & pbtIter) const noexcept{
        if(pbtIter.Stk == this->Stk && *(this->corrente) == *(pbtIter.corrente)) return true;
        return false;
    }

    //Comparison operators
    template <typename Data>
    bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data> & pbtIter) const noexcept{
        return !(*this == pbtIter);
    }

    template <typename Data>
    Data & BTPreOrderMutableIterator<Data>::operator*(){
        if(this->Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
            return const_cast<Data &>(this->corrente->Element()); 
        }
    }



    /****************************************************************************************/



    /***************************************************************************************/
    /*                            Costruttori  e Distruttori PostBT                        */
    /***************************************************************************************/

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> & bt){
        if(bt.Size()){
            corrente = &(bt.Root());
            radice = &(bt.Root());
            LeftMostChild();
        }
        
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator & bt){

        corrente = bt.corrente;
        radice = bt.radice;
        Stk = bt.Stk;

        
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator && bt){
        std::swap(corrente, bt.corrente);
        std::swap(radice, bt.radice);
        std::swap(Stk, bt.Stk);
        
    }

    template <typename Data>
    BTPostOrderIterator<Data>::~BTPostOrderIterator(){
        Stk.Clear();
        corrente = nullptr;
        radice = nullptr;
        //delete &Stk;
    }

    /***************************************************************************************/
    /*                             Funzioni Ausiliari PostBT                               */
    /***************************************************************************************/


    template <typename Data>
    void BTPostOrderIterator<Data>::LeftMostChild(){
        
        if(corrente == nullptr) return;

        while(corrente->HasLeftChild() || corrente->HasRightChild()){
            if(corrente->HasLeftChild()){
                Stk.Push(corrente);
                corrente = &(corrente->LeftChild());
            }else if(corrente->HasRightChild()){
                Stk.Push(corrente);
                corrente = &(corrente->RightChild());   
            }
        }
    }

    /***************************************************************************************/
    /*                             Operatori PostBT                                        */
    /***************************************************************************************/

    //incremento
    template <typename Data>
    BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator++(){
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }


        if(Stk.Empty()){
            corrente = nullptr;
        }else{

            if((Stk.Top())->HasLeftChild()){
                if(/* (*corrente) == (Stk.Top())->LeftChild()*/ corrente == &((Stk.Top())->LeftChild())){
                    if((Stk.Top())->HasRightChild()){
                        corrente = &((Stk.Top())->RightChild());
                        LeftMostChild();  
                    }else{
                        corrente = Stk.TopNPop();
                    }
                }else{
                    corrente = Stk.TopNPop();
                }
            }else if((Stk.Top())->HasRightChild()){
                if(/*(*corrente) == (Stk.Top())->RightChild()*/ corrente == &(Stk.Top())->RightChild()){
                    corrente = Stk.TopNPop();
                }
            }else{
                corrente = Stk.TopNPop();
            }

        }
        
        return *this;
    }

    // Copy assignment
    template <typename Data>
    BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator & bt){
        BTPostOrderIterator<Data> *tmp = new BTPostOrderIterator(bt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    // Move assignment
    template <typename Data>
    BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator=(BTPostOrderIterator && bt){
        std::swap(Stk, bt.Stk);
        std::swap(corrente, bt.corrente);
        std::swap(radice, bt.radice);
        return *this;
    }

    template <typename Data>
    const Data & BTPostOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
            return corrente->Element(); 
        }
        
    }

    //Comparison operators
    template <typename Data>
    bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data> & postbt) const noexcept{
        if(postbt.Stk == this->Stk && *corrente == *(postbt.corrente)) return true;
        return false;
    }

    //Comparison operators
    template <typename Data>
    bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data> & postbt) const noexcept{
        return !(*this == postbt);
    }


    /***************************************************************************************/
    /*                             Funzioni Specifiche PostBT                              */
    /***************************************************************************************/

    template <typename Data>
    bool BTPostOrderIterator<Data>::Terminated() const noexcept{
        return corrente == nullptr;
    }

    template <typename Data>
    void BTPostOrderIterator<Data>::Reset() noexcept{
        if(radice != nullptr){
            Stk.Clear();
            corrente = radice;
            LeftMostChild();
        }
        
    }



    /****************************************************************************************/


    /***************************************************************************************/
    /*                          Costruttori e distruttori PostMBT                          */
    /***************************************************************************************/

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data> & mbt){
        if(mbt.Size() > 0){
            this->corrente = &(mbt.Root());
            this->radice = this->corrente;
            this->LeftMostChild();
        }
        
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator & mbt){
        this->corrente = mbt.corrente;
        this->Stk = mbt.Stk;
        
        
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator && mbt){
        std::swap(this->corrente, mbt.corrente);
        std::swap(this->Stk, mbt.Stk);
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data>::~BTPostOrderMutableIterator(){
        this->Stk.Clear();
        this->corrente = nullptr;
        // delete Stk;
    }


    /***************************************************************************************/
    /*                                  Operatori PostMBT                                  */
    /***************************************************************************************/

    //Copy
    template <typename Data>
    BTPostOrderMutableIterator<Data> & BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator & mbt){
        BTPostOrderMutableIterator<Data> *tmp = new BTPostOrderMutableIterator(mbt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move
    template <typename Data>
    BTPostOrderMutableIterator<Data> & BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator && mbt){
        std::swap(this->Stk, mbt.Stk);
        std::swap(this->corrente, mbt.corrente);
        return *this;
    }

    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data> & postmbt) const noexcept{
        if(postmbt.Stk == this->Stk && *(this->corrente) == *(postmbt.corrente)) return true;
        return false;
    }

    //Comparison operators
    template <typename Data>
    bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data> & postmbt) const noexcept{
        return !(*this == postmbt);
    }

    template <typename Data>
    Data & BTPostOrderMutableIterator<Data>::operator*(){
        if(this->Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
            return const_cast<Data &>(this->corrente->Element()); 
        }
        
    }


    /****************************************************************************************/



    /***************************************************************************************/
    /*                       Costruttori e Distruttori InOrderBT                           */
    /***************************************************************************************/
    
    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> & bt){
        if(bt.Size() > 0){
            corrente = &(bt.Root());
            radice = &(bt.Root());
            LeftMostChild();
        }
    }

    //Copy 
    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator & bt){
        corrente = bt.corrente;
        radice = bt.radice;
        Stk = bt.Stk;

    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator && bt){
        std::swap(corrente,bt.corrente);
        std::swap(Stk, bt.Stk);
        std::swap(radice, bt.radice);
    }

    template <typename Data>
    BTInOrderIterator<Data>::~BTInOrderIterator(){
        Stk.Clear();
        corrente = nullptr;
        radice = nullptr;
        // delete &Stk;
    }


    /***************************************************************************************/
    /*                            Funzioni Ausliari InOrderBT                              */
    /***************************************************************************************/


    template <typename Data>
    void BTInOrderIterator<Data>::LeftMostChild(){
        
        if(corrente == nullptr) return;

        while(corrente->HasLeftChild()){
            if(corrente->HasLeftChild()){
                Stk.Push(corrente);
                corrente = &(corrente->LeftChild());
            }else{
                Stk.Push(corrente);
            }
        }

        if(corrente->HasRightChild()){
            Stk.Push(corrente);
        }

        if(!(corrente->HasLeftChild()) && !(corrente->HasRightChild())){
            Stk.Push(corrente);
        }

    }

    
    /***************************************************************************************/
    /*                                 Operatori InOrderBT                                 */
    /***************************************************************************************/

    //Copy
    template <typename Data>
    BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator=(BTInOrderIterator & bt){
        BTInOrderIterator<Data> *tmp = new BTInOrderIterator(bt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;

    }

    //Move
    template <typename Data>
    BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator=(BTInOrderIterator && bt){
        std::swap(Stk, bt.Stk);
        std::swap(corrente, bt.corrente);
        std::swap(radice, bt.radice);
        return *this;
    }


    template <typename Data>
    bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> & inmbt) const noexcept{
        if(inmbt.Stk == this->Stk && *(this->corrente) == *(inmbt.corrente)) return true;
        return false;
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> & inmbt) const noexcept{
        return !(*this == inmbt);
    }

    template <typename Data>
    const Data & BTInOrderIterator<Data>::operator*() const{
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
           return Stk.Top()->Element(); 
        }
    }

    template <typename Data>
    BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator++(){
        if(Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }
    
        corrente = Stk.TopNPop();
        if(corrente->HasRightChild()){
            corrente = &(corrente->RightChild());
            LeftMostChild();
        }

        if(Stk.Empty()){
            corrente = nullptr;
        }

        return *this;
    }

    /***************************************************************************************/
    /*                            Funzioni specifiche InOrderBT                            */
    /***************************************************************************************/

    template <typename Data>
    void BTInOrderIterator<Data>::Reset() noexcept{
        if(radice != nullptr){
            corrente = radice;
            Stk.Clear();
            LeftMostChild();
        }
        
    }

    template <typename Data>
    bool BTInOrderIterator<Data>::Terminated() const noexcept{
        return corrente == nullptr;
    }


    /*******************************************************************************************/


    /***************************************************************************************/
    /*                          Costruttori e distruttori InOrderMBT                       */
    /***************************************************************************************/

   
    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data> & mbt){
        if(mbt.Size() > 0){
            this->corrente = &(mbt.Root());
            this->radice = this->corrente;
            BTInOrderIterator<Data>::LeftMostChild();
        }
        
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> & mbt){
        this->corrente = mbt.corrente;
        this->Stk = mbt.Stk;
    }

    template <typename Data>
    BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator && bt){
        std::swap(this->corrente,bt.corrente);
        std::swap(this->Stk, bt.Stk);
    }
    template <typename Data>
    BTInOrderMutableIterator<Data>::~BTInOrderMutableIterator(){
        this->Stk.Clear();
        this->corrente = nullptr;
        // delete Stk;
    }

    /***************************************************************************************/
    /*                                  operatori InOrderMBT                               */
    /***************************************************************************************/

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data> & bt) const noexcept{
        if(bt.Stk == this->Stk && *(this->corrente) == *(bt.corrente)) return true;
        return false;
    }

    template <typename Data>
    bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data> & bt) const noexcept{
        return !(bt == *this);
    }
  
    template <typename Data>
    Data & BTInOrderMutableIterator<Data>::operator*(){
        if(this->Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
           return const_cast<Data &>(this->Stk.Top()->Element()); 
        }
        
    }
    
    // Copy assignment
    template <typename Data>
    BTInOrderMutableIterator<Data> & BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator & bt){
        BTInOrderMutableIterator<Data> *tmp = new BTInOrderMutableIterator(bt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    // Move assignment
    template <typename Data>
    BTInOrderMutableIterator<Data> & BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator && bt){
        std::swap(this->Stk, bt.Stk);
        std::swap(this->corrente, bt.corrente);
        return *this;
    }

    /*******************************************************************************************/


    /***************************************************************************************/
    /*                        Costruttore e Distruttore BTBreadthIterator                  */
    /***************************************************************************************/

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> & bt){
        radice = &(bt.Root());
        Que.Enqueue(radice);
    }

    // Copy constructor
    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> & bt){
        radice = bt.radice;
        Que = bt.Que;
    }

    //Move constructor
    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> && bt){
        std::swap(radice,bt.radice);
        std::swap(Que,bt.Que);
    }

    template <typename Data>
    BTBreadthIterator<Data>::~BTBreadthIterator(){
        Que.Clear();
        radice = nullptr;
        // delete &Que;
    }

    /***************************************************************************************/
    /*                             Operaotri BTBreadthIterator                             */
    /***************************************************************************************/

    template <typename Data>
    bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data> & bt) const noexcept{
        if(bt.Que == this->Que) return true;
        return false;
    }

    template <typename Data>
    bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data> & bt) const noexcept{
        return !(bt == *this);
    }

    // Copy assignment
    template <typename Data>
    BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator=(const BTBreadthIterator & bt){
        BTBreadthIterator<Data> *tmp = new BTBreadthIterator(bt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    // Move assignment
    template <typename Data>
    BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator=(BTBreadthIterator && bt){
        std::swap(this->Que, bt.Que);
        std::swap(this->radice, bt.radice);
        return *this;
    }

    template <typename Data>
    const Data & BTBreadthIterator<Data>::operator*() const {
        if(Terminated()) throw std::out_of_range("Sei andato troppo oltre!");
        return Que.Head()->Element();
    }

    template <typename Data>
    BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator++(){
        if(Terminated()) throw std::out_of_range("Sei andato troppo oltre!");
        
        if((Que.Head())->HasLeftChild()){
            Que.Enqueue(&(Que.Head())->LeftChild());
        }
        
        if((Que.Head())->HasRightChild()){
            Que.Enqueue(&(Que.Head())->RightChild());
        }
        
        Que.Dequeue();

        return *this;
    }


    /***************************************************************************************/
    /*                             Funzioni specifiche BTBreadthIterator                   */
    /***************************************************************************************/

    template <typename Data>
    bool BTBreadthIterator<Data>::Terminated() const noexcept{
        if(Que.Empty()) return true;
        return false;
    }

    template <typename Data>
    void BTBreadthIterator<Data>::Reset() noexcept{
        if(radice != nullptr){
            Que.Clear();
            Que.Enqueue(radice);
        }
        
    }

    /****************************************************************************************/


    /***************************************************************************************/
    /*                      Costruttori e distruttori BTBreadthMutableIterator             */
    /***************************************************************************************/

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data> & mbt){
        if(mbt.Size() > 0){
            this->Que.Enqueue(&(mbt.Root()));
            this->radice = &(mbt.Root());
        }
        
    }


    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator & mbt){
        this->Que = mbt.Que;
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator && mbt){
        std::swap(this->Que,mbt.Que);
    }

    template <typename Data>
    BTBreadthMutableIterator<Data>::~BTBreadthMutableIterator(){
        this->Que.Clear();
        // delete Que;
    }

    /***************************************************************************************/
    /*                      Funzioni specifiche BTBreadthMutableIterator                   */
    /***************************************************************************************/

    //Copy
    template <typename Data>
    BTBreadthMutableIterator<Data> & BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator & mbbt){
        BTBreadthMutableIterator<Data> *tmp = new BTBreadthMutableIterator(mbbt);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move
    template <typename Data>
    BTBreadthMutableIterator<Data> & BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator && mbbt){
        std::swap(this->Que, mbbt.Que);
        return *this;
    }

    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data> & mbbt) const noexcept{
        if(mbbt.Que == this->Que) return true;
        return false;
    }

    //Comparison operators
    template <typename Data>
    bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data> & mbbt) const noexcept{
        return !(*this == mbbt);
    }

    template <typename Data>
    Data & BTBreadthMutableIterator<Data>::operator*(){
        if(this->Terminated()){
            throw std::out_of_range("Sei andato troppo oltre!");
        }else{
            return const_cast<Data &>(this->Que.Head()->Element());
        }
        
    }

}
