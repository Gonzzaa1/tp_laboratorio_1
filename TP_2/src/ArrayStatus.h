#ifndef ARRAYSTATUS_H_
#define ARRAYSTATUS_H_

struct
{
    int id;
    char description[20];

}typedef StatusFlight;

#endif /* ARRAYSTATUS_H_ */


/** \brief
 *
 * \param status TypePassenger* Pointer to array of Status Flight
 * \param len int Array length
 * \param id int id of Status of Flight
 * \param pIndex int* pointer to index of array of Status Flight
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int searchStatus(StatusFlight* status, int len, int id, int* pIndex);
/** \brief
 *
 * \param status TypePassenger* Pointer to array of Status Flight
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printStatus(StatusFlight* status, int len);
/** \brief
 *
 * \param status TypePassenger* Pointer to array of Status Flight
 * \param len int Array length
 * \param id int id of Status of Flight
 * \param description[] char array of description of status flight
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadStatusDescription(StatusFlight* status, int len, int id, char description[]);
/** \brief
 *
 * \param status TypePassenger* Pointer to array of Status Flight
 * \param len int Array length
 * \param id int id of Status of Flight
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int valideStatus(StatusFlight* status, int len, int id);
int chooseStatus(int* id);
