/**
 * \file localsearch.hpp
 * \author dorian dumez
 * \brief define object to perform local search
 */

#ifndef LOCALSEARCH
#define LOCALSEARCH

#include "solution.hpp"
#include "pfspinstance.hpp"

/**
* \class LocalSearch : contains all neibouhoud relation
*/
class LocalSearch{
  private:
  	int choix; /*!< 1->transpose, 2-> exchange, 3->insert */
    bool PPD; /*!< true iff the local search is in deapest descent */
    bool dofor; /*!< true iff the local search in descent must be done with a for (and not a while)*/

  public:

    /**
    * \brief create a local search to parametrize (default 1,false,true)
    */
    LocalSearch();

  	/**
  	* \brief create an object to aplly a choosen neighborhoud relation in a local search
  	*
  	* \param[in] choix the index of the neighborhoud to use
    * \param[in] PPD the way to use the local search
  	*/
  	LocalSearch(const int choix, const bool PPD, const bool dofor);

    /**
    * \brief free the memory of the object
    */
    ~LocalSearch();

    /**
    * \brief improve the solution with the prevously defined way
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool search(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief use the neighborhoud relation in the defined way until no improvement are possible
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    void descent(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief to change to used neigborhoud relation
    *
    * \param[in] choix the index of the new relation to use
    */
    void changechoix(const int choix);

    /**
    * \brief to change the way of the neighborhoud relation is used
    *
    * \param[in] PPD the new value of this atribute
    */
    void changePPD(const bool PPD);

    /**
    * \brief to change the way to do a descent
    *
    * \param[in] dofor the new value of this atribute
    */
    void changedofor(const bool dofor);

  private:
    /**
    * \brief improve the solution with the transpose neighborhoud
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool transpose(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with the transpose neighborhoud (but doesn't stop at the first improvement)
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool transposedofor(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with transpose neighborhoud in deapest descent
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool transposePPD(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with exchange neighborhoud
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool exchange(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with exchange neighborhoud (but doesn't stop at the first improvement)
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool exchangedofor(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with exchange neighborhoud in deapest descent
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool exchangePPD(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with insert neighborhoud
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool insert(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with insert neighborhoud (but doesn't stop at the first improvement)
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool insertdofor(const PfspInstance & instance, Solution & sol) const;

    /**
    * \brief improve the solution with insert neighborhoud in deapest descent
    *
    * \param[in] instance the instance of the problem
    * \param[in,out] sol the solution to improve
    *
    * \return true iff the solution was imrove
    */
    bool insertPPD(const PfspInstance & instance, Solution & sol) const;

};

#endif