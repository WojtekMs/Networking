#include <string>

namespace networking::utils
{
void log_error(const std::string& error_msg);

/**
 * @brief this function is used to receive char data from stream sockets;
 * this function reads characters from the stream until the first occurence of '\0';
 *
 * @param buffer_size
 * @param socket_fd
 * @return std::string
 */
std::string receive_string(int socket_fd, int recv_flags = 0);

/**
 * @brief this functions is used to send char data by stream socket;
 * this function makes sure that all bytes were sent out, it sends out c style string
 * (null terminated);
 *
 * @param string
 * @param socket_fd
 */
void send_string(const std::string& string, int socket_fd, int send_flags = 0);

/**
 * @brief this function returns the maximum message size (the number of characters /
 * bytes); the value is calculated based on the networking::config::MESSAGE_HEADER_SIZE;
 *
 * @return int
 */
int max_message_size();

/**
 * @brief this function returns the message header;
 * the value returned is a string containing a number (the actual message size);
 * for the MESSAGE_HEADER_SIZE = 6, the message size = 10, header is:
 * '00010\0' ;
 *
 * @param message_size
 * @return std::string
 */
std::string get_message_header(int message_size);

}  // namespace networking::utils
