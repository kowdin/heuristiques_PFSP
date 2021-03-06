/**
 * \file solution.hpp
 * \author dorian dumez
 * \brief define object wich containt solution's information and function
 */

#ifndef SOLUTION
#define SOLUTION

#include <vector>

#include "pfspinstance.hpp"

class PfspInstance;

/**
* \class Solution : containt all solution's informations
*/
class Solution{
  private:
  	std::vector< int > solution; /*!<contains the job's index in the order they should be done */
  	int nbJobs; /*!< number of jobs to do */

  public:
    std::vector< std::vector <long int> > enddate; /*!<date of the end of the task of the machine on job, to re-calculate faster the wct */

  public:
  	/**
  	* \brief create an empty solution
  	*
  	* \param[in] instance the context of this solution
  	*/
  	Solution(const PfspInstance & instance);

    /**
    * \brief copy constructor
    *
    * \param[in] other the solution to copy
    * \param[in] copyEndDateTable allow to disable the copy of the end date table
    */
    Solution(const Solution & other, const bool copyEndDateTable = true);

    /**
    * \brief empty constructor, do nothing
    */
    Solution();

    /*
    * \brief to create a solution after a usage of the empty constructor
    *
    * \param[in] instance the context of this solution
    */
    void initialize(const PfspInstance & instance);

  	/**
  	* \brief free the memmory allocated to this solution
  	*/
  	~Solution();

  	/**
  	* \brief to get the jth job to do (start from 0)
  	*
  	* \param[in] the index of the jth job to do
  	*
  	* \return the index of the jth job to do
  	*/
  	int getJ(const int j) const;

    /**
    * \brief place the job j in the index i
    *
    * \param[in] i the index where to place the job
    * \param[in] j the index of the job to place
    */
    void setJ(const int i, const int j);

  	/**
  	* \brief Fill the solution with numbers between 1 and nbJobs, shuffled
  	*/
  	void randomPermutation();

  	/**
  	* \brief construct a solution with the RZ heuristic
  	*/
  	void constructRZ(const PfspInstance & instance);

    /**
    * \brief print this solution
    */
    void print() const;

  private:
  /**
	* \brief generate a random number in an interval
	*
	* \param[in] min the lower bound
	* \param[in] max the upper bound
	*
	* \return a random int between max and min
	*/
	int generateRndPosition(const int min, const int max) const;

};

#endif