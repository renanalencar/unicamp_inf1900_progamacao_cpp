#include "Player.h"

namespace ui {
	Player::Player() : Player(nullptr) {
		
	}

	Player::Player(CWnd* window)
		: BaseView<PlayerViewModel>(), BaseControl(window, 0, 0, PLAY_WIDTH, PLAY_HEIGHT)
	{
		m_pViewModel = std::make_shared<PlayerViewModel>(this,0,0);
	}

	void Player::addCard(std::shared_ptr<Card> card)
	{
		m_cards.push_back(card);
	}

	void Player::removeCard(std::shared_ptr<Card> card)
	{
		for (auto it = m_cards.begin(); it != m_cards.end(); it++) {
			if (*it == card) {
				m_cards.erase(it);
				break;
			}
		}
	}

	std::string Player::getNome() const
	{
		return m_nome;
	}

	void Player::draw()
	{
		int cardIndex = 0;
		int margin = 10;
		for(auto& card : m_cards){
			card->draw();
			card->move(getBounds()->left + (cardIndex * (margin + CARD_WIDTH)), getBounds()->top + margin);
			cardIndex++;
		}	
	}
	void Player::update()
	{
		draw();
	}
	void Player::setParent(CWnd* parent)
	{
		BaseControl::setParent(parent);
		for (auto& card : m_cards) {			
			card->setParent(parent);
		}
	}
}