#include <businessLogic/loginUC.h>
#include <database/userRepository.h>
#include <domain/user.h>


LoginUC::LoginUC(const std::shared_ptr<UserRepository> userRepository) :
    m_userRepository(userRepository)
{}

std::unique_ptr<User> LoginUC::login(const std::string & nan) const
{
    return m_userRepository->getUser(nan);
}