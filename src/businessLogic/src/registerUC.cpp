#include <businessLogic/registerUC.h>
#include <database/userRepository.h>

RegisterUC::RegisterUC(const std::shared_ptr<UserRepository> userRepository) :
                        m_userRepository(userRepository)
{
}

void RegisterUC::regist(const User & user)
{
    m_userRepository->createUser(user);
}