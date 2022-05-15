#ifndef ARRAYTYPES_H_
#define ARRAYTYPES_H_

struct
{
    int id;
    char description[20];

}typedef TypePassenger;

#endif /* ARRAYTYPES_H_ */

/** \brief
 *
 * \param type TypePassenger* Pointer to array of typePassenger
 * \param len int Array length
 * \param id int id of types of passengers
 * \param pIndex int* pointer to index of array of typePassenger
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int searchType(TypePassenger* type, int len, int id, int* pIndex);
/** \brief
 *
 * \param type TypePassenger* Pointer to array of typePassenger
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printType(TypePassenger* type, int len);
/** \brief
 *
 * \param type TypePassenger* Pointer to array of typePassenger
 * \param len int Array length
 * \param id int id of types of passengers
 * \param description[] char array of description of types passenger
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadTypeDescription(TypePassenger* type, int len, int id, char description[]);
/** \brief
 *
 * \param type TypePassenger* Pointer to array of typePassenger
 * \param len int Array length
 * \param id int id of types of passengers
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int valideType(TypePassenger* type, int len, int id);
int chooseType(int* id);
