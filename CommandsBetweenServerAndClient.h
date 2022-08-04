#pragma once

/// <summary>
/// Все команды серверу и ответы от сервера размещать в уже созданные enum class (поддержка до 999 команд)
/// Service Commands не трогать, используются в протоколах работы сервера и клиента
/// </summary>

enum class CommandToServer
{
	AUTHORIZATION,
	REGISTRATION,
	DISCONNECT,
	//Admin commands
	REDISTER_NEW_USER,
	BAN_CLIENT,
	BAN_EXPERT,
	UNBAN_CLIENT,
	UNBAN_EXPERT,
	DELETE_CLIENT,
	DELETE_EXPERT,
	FIND_CLIENT_BY_LOGIN,
	FIND_EXPERT_BY_LOGIN,
	FIND_ADMIN_BY_LOGIN,
	//Expert commands
	RATE,
	//ClientCommands
	//По сущностям
};

enum class AnswerFromServer
{
	SUCCESSFULLY,
	_ERROR,
	UNKNOWN_COMMAND
};

enum class TypeOfUser
{
	UNDEFINED,
	ADMIN,
	CLIENT, 
	EXPERT
};

enum class ServiceCommands
{
	READY_TO_RECEIVE,
};