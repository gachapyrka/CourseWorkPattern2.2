#pragma once

/// <summary>
/// ��� ������� ������� � ������ �� ������� ��������� � ��� ��������� enum class (��������� �� 999 ������)
/// Service Commands �� �������, ������������ � ���������� ������ ������� � �������
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
	//�� ���������
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