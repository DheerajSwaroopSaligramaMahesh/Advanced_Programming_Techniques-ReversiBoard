/*
 * global.h
 *
 *  Created on: 05-Nov-2024
 *      Author: Dheeraj Swaroop S M
 */

/**
 * @file global.h
 * @brief Contains common type definitions and error codes.
 *
 * This header file defines error codes used across the project for consistency.
 * The RC_t enum provides various return codes to handle error and success states.
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

/**
 * @enum RC_t
 * @brief Return codes for various operations.
 *
 * This enum contains standard return codes used throughout the project. It includes:
 * - RC_OK: Operation was successful.
 * - RC_ERROR: General error.
 * - RC_ERROR_PARAM_OUTOFRANGE: Invalid parameter value, out of range.
 * - RC_ERROR_BAD_PARAM: Invalid parameter.
 */

typedef enum
{
	RC_OK, RC_ERROR, RC_ERROR_PARAM_OUTOFRANGE, RC_ERROR_BAD_PARAM,

} RC_t;

#endif /* GLOBAL_H_ */
