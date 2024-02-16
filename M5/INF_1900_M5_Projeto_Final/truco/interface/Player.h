#pragma once
#include <vector>
#include "PlayerViewModel.h"
#include "BaseControl.h"
#include "Card.h"

namespace ui {

	class Player : public BaseView<PlayerViewModel>, public BaseControl
	{
	private:
		std::vector<Card*> m_cards;
		std::string m_nome;

	public:		
		Player();
		Player(CWnd* window);		
		void addCard(Card* card);
		void removeCard(Card* card);
		std::string getNome() const;


		// Inherited via BaseView
		void draw() override;
		void update() override;
		void setParent(CWnd* parent) override;
	};

}