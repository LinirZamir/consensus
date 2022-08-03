#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>

DEFINE_string(protocol, "baidu_std", "Protocol type. Defined in src/brpc/options.proto");
DEFINE_string(connection_type, "", "Connection type. Available values: single, pooled, short");
DEFINE_string(server, "0.0.0.0:8000", "IP Address of server");
DEFINE_int32(timeout_ms, 100, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)"); 
DEFINE_string(load_balancer, "", "The algorithm for load balancing");


int main(int argc, char* argv[]){

	// A Channel represents a communication line to a Server.  
    // Channel is thread-safe and can be shared by all threads the your program.
	brpc::Channel channel;

    // Initialize the channel, NULL means using default options.
	brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.connection_type = FLAGS_connection_type;
    options.timeout_ms = FLAGS_timeout_ms;
    options.max_retry = FLAGS_max_retry;

	if (channel.Init(FLAGS_server.c_str(),FLAGS_load_balancer.c_str(), &options) != 0){
		//LOG(ERROR) << "Fail to initialize channel";
		return -1;
	}
	

return 0;
}
