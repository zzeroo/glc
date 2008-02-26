/**
 * \file src/common/state.h
 * \brief glc state interface
 * \author Pyry Haulos <pyry.haulos@gmail.com>
 * \date 2007-2008
 * For conditions of distribution and use, see copyright notice in glc.h
 */

/**
 * \addtogroup common
 *  \{
 * \defgroup state glc state
 *  \{
 */

#ifndef _STATE_H
#define _STATE_H

#include "glc.h"

/** all stream operations should cancel */
#define GLC_STATE_CANCEL     0x1

/**
 * \brief video stream object
 */
typedef struct glc_state_ctx_s* glc_state_ctx_t;

/**
 * \brief audio stream object
 */
typedef struct glc_state_audio_s* glc_state_audio_t;

/**
 * \brief initialize state
 * \param glc glc
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_init(glc_t *glc);

/**
 * \brief destroy state
 * \param glc glc
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_destroy(glc_t *glc);

/**
 * \brief acquire a new video stream
 * \param glc glc
 * \param ctx_i returned video stream number
 * \param ctx returned video stream object
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_ctx_new(glc_t *glc, glc_ctx_i *ctx_i,
			       glc_state_ctx_t *ctx);

/**
 * \brief acquire a new audio stream
 * \param glc glc
 * \param audio_i returned audio stream number
 * \param audio returned audio stream object
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_audio_new(glc_t *glc, glc_audio_i *audio_i,
				 glc_state_audio_t *audio);

/**
 * \brief set state flag
 * \param glc glc
 * \param flag flag to set
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_set(glc_t *glc, int flag);

/**
 * \brief clear state flag
 * \param glc glc
 * \param flag flag to clear
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_clear(glc_t *glc, int flag);

/**
 * \brief test state flag
 * \note for performance reasons this function doesn't acquire
 *       a global state mutex lock.
 * \param glc glc
 * \param flag flag to test
 * \return 1 if flag is set, otherwise 0
 */
__PUBLIC __inline__ int glc_state_test(glc_t *glc, int flag);

/**
 * \brief get state time
 *
 * State time is glc_time() minus current state time difference.
 * \note doesn't acquire a global time difference lock
 * \param glc glc
 * \return current state time
 */
__PUBLIC glc_utime_t glc_state_time(glc_t *glc);

/**
 * \brief add value to state time difference
 * \param glc glc
 * \param diff new time difference
 * \return 0 on success otherwise an error code
 */
__PUBLIC int glc_state_time_add_diff(glc_t *glc, glc_stime_t diff);

#endif

/**  \} */
/**  \} */
