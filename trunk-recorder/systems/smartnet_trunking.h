#ifndef SMARTNET_TRUNKING
#define SMARTNET_TRUNKING

#include <boost/math/constants/constants.hpp>
#include <boost/log/trivial.hpp>

#include <gnuradio/hier_block2.h>
#include <gnuradio/msg_queue.h>
#include <gnuradio/message.h>
#include <gnuradio/blocks/file_sink.h>
#include <gnuradio/gr_complex.h>

#include <gnuradio/filter/freq_xlating_fir_filter_ccf.h>
#include <gnuradio/filter/firdes.h>
#include <gnuradio/filter/firdes.h>
#include <gnuradio/filter/fir_filter_ccf.h>
#include <gnuradio/filter/fir_filter_ccf.h>
#include <gnuradio/filter/fft_filter_ccf.h>
#include <gnuradio/digital/fll_band_edge_cc.h>
#include <gnuradio/digital/clock_recovery_mm_ff.h>
#include <gnuradio/digital/binary_slicer_fb.h>
#include <gnuradio/digital/correlate_access_code_tag_bb.h>

#include <gnuradio/analog/pll_freqdet_cf.h>
#include <gnuradio/analog/sig_source_f.h>
#include <gnuradio/analog/sig_source_c.h>
#include <gnuradio/blocks/copy.h>
#include <gnuradio/blocks/null_sink.h>
#include "../../gr_blocks/freq_xlating_fft_filter.h"

#include "smartnet_decode.h"
class smartnet_trunking;

typedef boost::shared_ptr<smartnet_trunking> smartnet_trunking_sptr;

smartnet_trunking_sptr make_smartnet_trunking(float f, float c, long s, gr::msg_queue::sptr queue, int sys_id);

class smartnet_trunking : public gr::hier_block2
{
								friend smartnet_trunking_sptr make_smartnet_trunking(float f, float c, long s, gr::msg_queue::sptr queue, int sys_id);
public:
								void tune_offset(double f);
								void enable();
protected:
								gr::blocks::copy::sptr valve;
								//gr::filter::freq_xlating_fir_filter_ccf::sptr prefilter;
								freq_xlating_fft_filter_sptr prefilter;
								smartnet_trunking(float f, float c, long s, gr::msg_queue::sptr queue, int sys_id);
								double samp_rate, chan_freq, center_freq;
								int sys_id;

								gr::blocks::null_sink::sptr null_sink;
};


#endif
